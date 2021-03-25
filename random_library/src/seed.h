#ifndef _CLIB_SEED_H
#define _CLIB_SEED_H

extern int seedGenerated;

void clib_rand_seed_time();
void clib_rand_seed(unsigned seed);

#endif