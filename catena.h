#ifndef SYMM_CATENA_H
#define SYMM_CATENA_H

#include <shim/macros.h>
#include <shim/operations.h>
#include <shim/errors.h>
#include "macros.h"
#include "ubi512.h"
#include "graph_hashing.h"

#define SYMM_CATENA_SALT_BITS		256
#define SYMM_CATENA_SALT_BYTES		32
#define SYMM_CATENA_MAX_PASSWORD_BYTES	120
#define SYMM_CATENA_TWEAK_BYTES		(SYMM_THREEFISH512_BLOCK_BYTES + 1 + 1 + 2 + 2)
#define SYMM_CATENA_RNG_BYTES		SYMM_THREEFISH512_BLOCK_BYTES
#define SYMM_CATENA_DOMAIN_PWSCRAMBLER	UINT8_C (0)
#define SYMM_CATENA_DOMAIN_KDF		UINT8_C (1)
#define SYMM_CATENA_DOMAIN_POW		UINT8_C (2)
#define SYMM_CATENA_MHF_TEMP_BYTES	SYMM_GRAPH_HASHING_TEMP_BYTES

enum {
	SYMM_CATENA_SUCCESS,
	SYMM_CATENA_ALLOC_FAILURE
};

#define WORD_ALIGN_ 		SHIM_ALIGNAS (uint64_t)

typedef struct {
	Symm_UBI512		ubi512_ctx;
	uint8_t *		graph_memory;
	WORD_ALIGN_ uint8_t	x_buffer [SYMM_THREEFISH512_BLOCK_BYTES];
	WORD_ALIGN_ uint8_t	salt     [SYMM_CATENA_SALT_BYTES];
	union {
		uint8_t             tw_pw_salt	[SYMM_CATENA_TWEAK_BYTES + SYMM_CATENA_MAX_PASSWORD_BYTES + SYMM_CATENA_SALT_BYTES];
		WORD_ALIGN_ uint8_t flap	[SYMM_THREEFISH512_BLOCK_BYTES * 3];
		WORD_ALIGN_ uint8_t catena	[SYMM_THREEFISH512_BLOCK_BYTES + 1];
		WORD_ALIGN_ uint8_t phi		[SYMM_THREEFISH512_BLOCK_BYTES * 2];
		WORD_ALIGN_ uint8_t mhf		[SYMM_CATENA_MHF_TEMP_BYTES];
		struct {
			WORD_ALIGN_ uint8_t word_buf [SYMM_THREEFISH512_BLOCK_BYTES * 2];
			WORD_ALIGN_ uint8_t rng      [SYMM_CATENA_RNG_BYTES];
		} gamma;
	} temp;
} Symm_Catena;

SHIM_BEGIN_DECLS

SYMM_API int
symm_catena_nophi (Symm_Catena * SHIM_RESTRICT ctx,
		   uint8_t *     SHIM_RESTRICT output,
		   uint8_t *     SHIM_RESTRICT password,
		   int const                   password_size,
		   uint8_t const               g_low,
		   uint8_t const               g_high,
		   uint8_t const               lambda);
SYMM_API int
symm_catena_usephi (Symm_Catena * SHIM_RESTRICT ctx,
		    uint8_t *     SHIM_RESTRICT output,
		    uint8_t *     SHIM_RESTRICT password,
		    int const                   password_size,
		    uint8_t const               g_low,
		    uint8_t const               g_high,
		    uint8_t const               lambda);

SHIM_END_DECLS
#undef WORD_ALIGN_
#endif // ~ SYMM_CATENA_H
