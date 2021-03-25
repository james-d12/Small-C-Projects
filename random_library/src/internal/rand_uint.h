#ifndef _CLIB_RAND_UINT_H
#define _CLIB_RAND_UINT_H

#include "seed.h"

/* TYPES

- UNSIGNED INT
- UNSIGNED LONG INT
- UNSIGNED LONG LONG INT
- UNSIGNED CHAR

*/

typedef unsigned int clib_uint;
typedef unsigned char clib_uchar;
typedef unsigned long int clib_ulint;
typedef unsigned long long int clib_ullint;

clib_uint clib_rand_uint(clib_uint min, clib_uint max);
clib_uint clib_rand_uint_array(int amount, clib_uint min, clib_uint max);
clib_uint clib_rand_uint_limit();
clib_uint clib_rand_uint_limit_array(int amount);

clib_ulint clib_rand_ulint(clib_ulint min, clib_ulint max);
clib_ulint clib_rand_ulint_array(int amount, clib_ulint min, clib_ulint max);
clib_ulint clib_rand_ulint_limit();
clib_ulint clib_rand_ulint_limit_array(int amount);

clib_ullint clib_rand_ullint(clib_ullint min, clib_ullint max);
clib_ullint clib_rand_ullint_array(int amount, clib_ullint min, clib_ullint max);
clib_ullint clib_rand_ullint_limit();
clib_ullint clib_rand_ullint_limit_array(int amount);

#endif