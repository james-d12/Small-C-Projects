#include <stdio.h>
#include <stdlib.h>

#include "pnt2.h"

#ifdef _CMATH_GEOMETRY_USE_POINTER

Pnt2* pnt2_new_null() { return malloc(sizeof(Pnt2)); }

Pnt2* pnt2_new(geom_t x, geom_t y)
{
    Pnt2* newPnt2 = malloc(sizeof(Pnt2));
    newPnt2->x = x;
    newPnt2->y = y;
    return newPnt2;
}

Pnt2* pnt2_copy(Pnt2* pnt2)
{
    return pnt2_new(pnt2->x, pnt2->y);
}

void pnt2_delete(Pnt2** pnt2)
{
    free(*pnt2);
    (*pnt2) = NULL;
}

void pnt2_print(Pnt2* pnt2)
{
#ifdef _CMATH_GEOMETRY_LDOUBLE
    printf("( %Lf %Lf )\n",pnt2->x, pnt2->y);
#else
    printf("( %f %f )\n",pnt2->x, pnt2->y);
#endif
}

#else

Pnt2 pnt2_new_null() 
{ 
    Pnt2* newPnt2 =  malloc(sizeof(Pnt2)); 
    return *newPnt2;
}

Pnt2 pnt2_new(geom_t x, geom_t y)
{
    Pnt2* newPnt2 = malloc(sizeof(Pnt2));
    newPnt2->x = x;
    newPnt2->y = y;
    return *newPnt2;
}

Pnt2 pnt2_copy(Pnt2 pnt2)
{
    return pnt2_new(pnt2.x, pnt2.y);
}

void pnt2_delete(Pnt2* pnt2)
{
    free(pnt2);
    pnt2 = NULL;
}

void pnt2_print(Pnt2 pnt2)
{
#ifdef _CMATH_GEOMETRY_LDOUBLE
    printf("( %Lf %Lf )\n",pnt2.x, pnt2.y);
#else
    printf("( %f %f )\n",pnt2.x, pnt2.y);
#endif
}

#endif

void pnt2_assign(Pnt2* dest, const Pnt2* src)
{
    dest->x = src->x;
    dest->y = src->y;
}