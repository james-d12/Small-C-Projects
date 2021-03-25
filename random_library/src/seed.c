#include "seed.h"
#include <time.h>
#include <stdlib.h>
 
int seedGenerated = 0;

void clib_rand_seed_time()
{
    srand(time(0));
    seedGenerated = 1;
}

void clib_rand_seed(unsigned seed)
{
    srand(seed);
    seedGenerated = 1;
}
