#include "rand_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void assert(int expr, const char* msg)
{
    if(expr == 1) { printf("%s\n",msg); exit(EXIT_FAILURE); }
}

int clib_rand_int(int min, int max)
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return min + (int) (rand()) /((int)(RAND_MAX/(max-min)));
}

int* clib_rand_int_array(int amount, int min, int max)
{
    int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_int(min,max); }
    return data;
}

int clib_rand_int_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return INT_MIN + (int) (rand()) /((int)(RAND_MAX/(INT_MAX-INT_MIN)));
}

int* clib_rand_int_limit_array(int amount)
{
    int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_int_limit(); }
    return data;
}

short int  clib_rand_shint(short int min, short int max)
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return min + (short int) (rand()) /((short int)(RAND_MAX/(max-min)));
}

short int* clib_rand_shint_array(int amount, short int min, short int max)
{
    short int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_shint(min,max); }
    return data;
}

short int  clib_rand_shint_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return SHRT_MIN + (short int) (rand()) /((short int)(RAND_MAX/(SHRT_MAX-SHRT_MIN)));
}

short int* clib_rand_shint_limit_array(int amount)
{
    short int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_shint_limit(); }
    return data;
}

long int clib_rand_lint(long int min, long int max)
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return min + (long int) (rand()) /((long int)(RAND_MAX/(max-min)));
}

long int* clib_rand_lint_array(int amount, long int min, long int max)
{
    long int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_lint(min,max); }
    return data;
}

long int clib_rand_lint_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return LONG_MIN + (long int) (rand()) /((long int)(RAND_MAX/(LONG_MAX-LONG_MIN)));
}

long int* clib_rand_lint_limit_array(int amount)
{
    long int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_lint_limit(); }
    return data;
}

long long int  clib_rand_llint(long long int min, long long int max)
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return min + (long long int) (rand()) /((long long int)(RAND_MAX/(max-min)));
}

long long int* clib_rand_llint_array(int amount, long long int min, long long int max)
{
    long long int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_llint(min,max); }
    return data;
}

long long int clib_rand_llint_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!\n");
    return LLONG_MIN + (long long int) (rand()) /((long long int)(RAND_MAX/(LLONG_MAX-LLONG_MIN)));
}

long long int* clib_rand_llint_limit_array(int amount)
{
    long long int* data = malloc(sizeof(*data) * amount);
    assert((data != NULL),"Could not allocate memory!\n");
    for(int i = 0; i < amount; i++) { data[i] = clib_rand_llint_limit(); }
    return data;
}