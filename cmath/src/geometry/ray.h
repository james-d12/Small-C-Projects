#ifndef _CMATH_RAY_H
#define _CMATH_RAY_H

#include "math/vec2.h"
#include "math/vec3.h"

typedef struct Ray2D
{
    Vec2 pos;
    Vec2 dir;
};

typedef struct Ray3D
{
    Vec3 pos;
    Vec3 dir;
};

#endif