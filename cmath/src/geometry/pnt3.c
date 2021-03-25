#include <stdio.h>
#include <stdlib.h>

#include "pnt3.h"

#ifdef _CMATH_GEOMETRY_USE_POINTER

Pnt3* pnt3_new_null()
{
    return malloc(sizeof(Pnt3));
}

Pnt3* pnt3_new(geom_t x, geom_t y, geom_t z)
{
    Pnt3* newPnt3 = malloc(sizeof(Pnt3));
    newPnt3->x = x;
    newPnt3->y = y;
    newPnt3->z = z;
    return newPnt3;
}

Pnt3* pnt3_copy(Pnt3* pnt3)
{
    return pnt3_new(pnt3->x,pnt3->y,pnt3->z);
}

void  pnt3_delete(Pnt3** pnt3)
{
    free(*pnt3);
    (*pnt3) = NULL;
}

void  pnt3_print(Pnt3* pnt3)
{
#ifdef _CMATH_GEOMETRY_LDOUBLE
    print("( %Lf %Lf %Lf )\n",pnt3->x, pnt3->y, pnt3->z);
#else
    print("( %f %f %f )\n",pnt3->x, pnt3->y, pnt3->z);
#endif
}

#else

Pnt3 pnt3_new_null()
{
    Pnt3* newPnt3 = malloc(sizeof(Pnt3));
    return *newPnt3;
}

Pnt3 pnt3_new(geom_t x, geom_t y, geom_t z)
{
    Pnt3* newPnt3 = malloc(sizeof(Pnt3));
    newPnt3->x = x;
    newPnt3->y = y;
    newPnt3->z = z;
    return *newPnt3;
}

Pnt3 pnt3_copy(Pnt3 pnt3)
{
    return pnt3_new(pnt3.x,pnt3.y,pnt3.z);
}

void pnt3_delete(Pnt3* pnt3)
{
    free(pnt3);
    pnt3 = NULL;
}

void pnt3_print(Pnt3 pnt3)
{
#ifdef _CMATH_GEOMETRY_LDOUBLE
    print("( %Lf %Lf %Lf )\n",pnt3.x, pnt3.y, pnt3.z);
#else
    print("( %f %f %f )\n",pnt3.x, pnt3.y, pnt3.z);
#endif
}

#endif

void pnt3_assign(Pnt3* dest, const Pnt3* src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
}