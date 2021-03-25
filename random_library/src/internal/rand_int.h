#ifndef _CLIB_RAND_INT_H
#define _CLIB_RAND_INT_H

#include "seed.h"

int  clib_rand_int(int min, int max);
int* clib_rand_int_array(int amount, int min, int max);
int  clib_rand_int_limit();
int* clib_rand_int_limit_array(int amount);

short int  clib_rand_shint(short int min, short int max);
short int* clib_rand_shint_array(int amount, short int min, short int max);
short int  clib_rand_shint_limit();
short int* clib_rand_shint_limit_array(int amount);

long int  clib_rand_lint(long int min, long int max);
long int* clib_rand_lint_array(int amount, long int min, long int max);
long int  clib_rand_lint_limit();
long int* clib_rand_lint_limit_array(int amount);

long long int  clib_rand_llint(long long int min, long long int max);
long long int* clib_rand_llint_array(int amount, long long int min, long long int max);
long long int  clib_rand_llint_limit();
long long int* clib_rand_llint_limit_array(int amount);


#endif