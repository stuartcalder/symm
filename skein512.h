#ifndef SYMM_SKEIN512_H
#define SYMM_SKEIN512_H

#include <shim/macros.h>
#include "ubi512.h"
#include "macros.h"

SHIM_BEGIN_DECLS

SYMM_API void
symm_skein512_hash (Symm_UBI512 * SHIM_RESTRICT ubi512_ctx,
      		    uint8_t *                   bytes_out,
      		    uint8_t const *             bytes_in,
      		    int64_t const               num_bytes_in,
      		    int64_t const               num_bytes_out);
SYMM_API void
symm_skein512_hash_native (Symm_UBI512 * SHIM_RESTRICT ubi512_ctx,
	     		   uint8_t *                   bytes_out,
	     		   uint8_t const *             bytes_in,
	     		   int64_t const               num_bytes_in);
SYMM_API void
symm_skein512_mac (Symm_UBI512 *   SHIM_RESTRICT ubi512_ctx,
		   uint8_t *                     bytes_out,
		   uint8_t const *               bytes_in,
		   uint8_t const * SHIM_RESTRICT key_in,
		   int64_t const                 num_bytes_in,
		   int64_t const                 num_bytes_out);

SHIM_END_DECLS


#endif // ~ SYMM_SKEIN512_H
