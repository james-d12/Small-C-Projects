#include "rand_float.h"

#include <stdio.h>
#include <stdlib.h>

void assert(int expr, const char* msg)
{
    if(expr == 1) { printf("%s\n",msg); exit(EXIT_FAILURE); }
}

float clib_rand_float(float min, float max)
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return min + (float) (rand()) /((float)(RAND_MAX/(max-min)));
}

float* clib_rand_float_array(int amount,float min, float max)
{
    float* data = malloc(sizeof(*data) * amount);
    if(!data) 
    { 
        free(data); 
        return NULL; 
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = clib_rand_float(min,max);
    }
    return data;
}

float clib_rand_float_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return FLT_MIN + (float) (rand()) /((float)(RAND_MAX/(FLT_MAX-FLT_MIN)));
}

float* clib_rand_float_limit_array(int amount)
{
    float* data = malloc(sizeof(*data) * amount);
    if(!data)
    {
        free(data);
        return NULL;
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = clib_rand_float_limit();
    }
    return data;
}

double clib_rand_double(double min, double max)
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return min + (double) (rand()) /((double)(RAND_MAX/(max-min)));
}

double* clib_rand_double_array(int amount, double min, double max)
{
    double* data = malloc(sizeof(*data) * amount);
    if(!data)
    {
        free(data);
        return NULL;
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = clib_rand_double(min,max);
    }
    return data;
}

double clib_rand_double_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return DBL_MIN + (double) (rand()) /((double)(RAND_MAX/(DBL_MAX-DBL_MIN)));
}

long double clib_rand_ldouble(long double min, long double max)
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return min + (long double) (rand()) /((long double)(RAND_MAX/(max-min)));
}

long double* clib_rand_ldouble_array(int amount, long double min, long double max)
{
    long double* data = malloc(sizeof(*data) * amount);
    if(!data)
    {
        free(data);
        return NULL;
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = clib_rand_ldouble(min,max);
    }
    return data;
}

long double clib_rand_ldouble_limit()
{
    assert(seedGenerated == 0, "Seed must be generated first!");
    return LDBL_MIN + (long double) (rand()) /((long double)(RAND_MAX/(LDBL_MAX-LDBL_MIN)));
}

long double* clib_rand_ldouble_limit_array(int amount)
{
    long double* data = malloc(sizeof(*data) * amount);
    if(!data)
    {
        free(data);
        return NULL;
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = clib_rand_ldouble_limit();
    }
    return data;
}