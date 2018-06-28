from distutils.core import setup, Extension

tribus_hash_module = Extension('sonoa_hash',
                               sources = ['sonoamodule.c',
                                          'sonoa.c',
										  	'sph/aes_helper.c',
										  	'sph/blake.c',
											'sph/bmw.c',
											'sph/groestl.c',
											'sph/jh.c',
										  	'sph/keccak.c',
										  	'sph/skein.c',
										  	'sph/luffa.c',
										  	'sph/cubehash.c',
										  	'sph/shavite.c',
											'sph/simd.c',
										  	'sph/echo.c',
										  	'sph/hamsi.c',
										  	'sph/fugue.c',
										  	'sph/shabal.c',
										  	'sph/whirlpool.c',
										  	'sph/sha2.c',
										  	'sph/haval.c'],

                               include_dirs=['.', './sph'])

setup (name = 'sonoa_hash',
       version = '1.0',
       description = 'Bindings for SonoA proof of work used by ProjectSONO',
       ext_modules = [tribus_hash_module])
