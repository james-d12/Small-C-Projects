#ifndef _CMATH_PNT3_H
#define _CMATH_PNT3_H

#include "../core.h"

typedef struct Pnt3
{
    geom_t x,y,z;
}Pnt3;

#ifdef _CMATH_GEOMETRY_USE_POINTER

Pnt3* pnt3_new_null();
Pnt3* pnt3_new(geom_t x, geom_t y, geom_t z);
Pnt3* pnt3_copy(Pnt3* pnt3);
void  pnt3_delete(Pnt3** pnt3);
void  pnt3_print(Pnt3* pnt3);

#else

Pnt3 pnt3_new_null();
Pnt3 pnt3_new(geom_t x, geom_t y, geom_t z);
Pnt3 pnt3_copy(Pnt3 pnt3);
void pnt3_delete(Pnt3* pnt3);
void pnt3_print(Pnt3 pnt3);

#endif

void pnt3_assign(Pnt3* dest, const Pnt3* src);

#endif