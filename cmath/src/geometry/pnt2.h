#ifndef _CMATH_PNT2_H
#define _CMATH_PNT2_H

#include "../core.h"

typedef struct Pnt2
{
    geom_t x ,y;
}Pnt2;

#ifdef _CMATH_GEOMETRY_USE_POINTER

Pnt2* pnt2_new_null();
Pnt2* pnt2_new(geom_t x, geom_t y);
Pnt2* pnt2_copy(Pnt2* pnt2);
void  pnt2_delete(Pnt2** pnt2);
void  pnt2_print(Pnt2* pnt2);

#else

Pnt2 pnt2_new_null();
Pnt2 pnt2_new(geom_t x, geom_t y);
Pnt2 pnt2_copy(Pnt2 pnt2);
void pnt2_delete(Pnt2* pnt2);
void pnt2_print(Pnt2 pnt2);

#endif

void pnt2_assign(Pnt2* dest, const Pnt2* src);

#endif