# symm
Symmetric Crytography
## Purpose
A simple C library implementing the SHA3 competition finalist Skein, its block cipher Threefish, and the Password Hashing Competition finalist, CATENA.
## Dependencies
-	[meson](https://mesonbuild.com) Build System
-	[shim](https://github.com/stuartcalder/shim) OS Abstraction Library
### Building Shim
#### On Linux
1. Build and install [shim](https://github.com/stuartcalder/shim).
2. Execute the following:
```
	$ mkdir builddir
	$ meson --backend=ninja --prefix=/usr builddir
	$ cd builddir
	$ ninja
	# ninja install
```
#### On OSX, BSDs
1. Build and install [shim](https://github.com/stuartcalder/shim).
2. Execute the following:
```
	$ mkdir builddir
	$ meson --backend=ninja builddir
	$ cd builddir
	$ ninja
	# ninja install
```
#### On Windows
1. git clone [shim](https://github.com/stuartcalder/shim) and cd into it.
2. Open an __"x64 Native Tools Command Prompt for VS 2019"__ cmd prompt, then cd into the cloned shim project directory.
3. Execute the following:
```
	mkdir builddir
	meson --backend=ninja builddir
	cd builddir
	ninja
	ninja install
```