#ifndef _CMATH_CORE_H
#define _CMATH_CORE_H

#include "config.h"

//OS checks
#if defined(__WIN16)
#define _CMATH_OS_WIN16
#else
    #if defined(__WIN32)
        #if defined(__WIN64)
            #define _CMATH_OS_WIN64
        #else
            #define _CMATH_OS_WIN32
        #endif
    #endif
#endif
#if defined(__gnu_linux__) || (__linux__)
#define _CMATH_OS_LINUX
#endif

//compiler checks
#if defined(__GNUC__)
# if defined(__GNUC_PATCHLEVEL__)
#  define __GNUC_VERSION__ (__GNUC__ * 10000 \
                            + __GNUC_MINOR__ * 100 \
                            + __GNUC_PATCHLEVEL__)
# else
#  define __GNUC_VERSION__ (__GNUC__ * 10000 \
                            + __GNUC_MINOR__ * 100)
# endif
#endif
#if defined(__MINGW32__)
#define _CMATH_COMPILER_MINGW32
#elif (__MINGW64)
#define _CMATH_COMPILER_MINGW64
#endif
#if defined(__clang__)
#define _CMATH_COMPILER_CLANG
#endif

//standard checks
#if defined(__STDC__)
# define _CMATH_STANDARD_C89
# if defined(__STDC_VERSION__)
#  if (__STDC_VERSION__ >= 199409L)
#   define _CMATH_STANDARD_C99
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define _CMATH_STANDARD_C11
#  endif
# endif
#endif

//check config flags

#ifdef _CMATH_MAT_DOUBLE
typedef double mat_t;
#elif defined _CMATH_MAT_LDOUBLE
typedef long double mat_t;
#else
typedef float mat_t;
#endif

#ifdef _CMATH_VEC_DOUBLE
typedef double vec_t;
#elif defined _CMATH_VEC_LDOUBLE
typedef long double vec_t;
#else
typedef float vec_t;
#endif

#ifdef _CMATH_GEOMETRY_DOUBLE
typedef double geom_t;
#elif defined _CMATH_GEOMETRY_LDOUBLE
typedef long double geom_t;
#endif
typedef float geom_t;
#endif
