#include <float.h>
#include <stdlib.h>

#include "test_helper.h"

double test_rand_double(double min, double max)
{
    return min + (double) (rand()) /((double)(RAND_MAX/(max-min)));
}

double* test_rand_double_array(int amount, double min, double max)
{
    double* data = malloc(sizeof(*data) * amount);
    if(!data)
    {
        free(data);
        return NULL;
    }

    for(int i = 0; i < amount; i++)
    {
        data[i] = test_rand_double(min,max);
    }
    return data;
}