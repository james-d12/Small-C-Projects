#ifndef _CLIB_RAND_FLOAT_H
#define _CLIB_RAND_FLOAT_H

#include "seed.h"
#include <float.h>

float   clib_rand_float(float min, float max);
float*  clib_rand_float_array(int amount, float min, float max);
float   clib_rand_float_limit();
float*  clib_rand_float_limit_array(int amount);

double  clib_rand_double(double min, double max);
double* clib_rand_double_array(int amount, double min, double max);
double  clib_rand_double_limit();
double* clib_rand_double_limit_array(int amount);

long double  clib_rand_ldouble(long double min, long double max);
long double* clib_rand_ldouble_array(int amount, long double min, long double max);
long double  clib_rand_ldouble_limit();
long double* clib_rand_ldouble_limit_array(int amount);

#endif