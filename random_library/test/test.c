#include "seed.h"
#include "rand.h"
#include <stdio.h>

void print_array(float* data, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Value: %f\n", data[i]);
    }
}

int main()
{
    clib_rand_seed_time();
    
    int randInt = clib_rand_int_limit();

    printf("Random integer: %d\n",randInt);

    return 0;
}