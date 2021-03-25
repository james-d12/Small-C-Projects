#include "rand_uint.h"

#include <stdio.h>
#include <stdlib.h>

void assert(int expr, const char* msg)
{
    if(expr == 1) { printf("%s\n",msg); exit(EXIT_FAILURE); }
}