#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"

#ifdef _CMATH_VEC_USE_POINTER

Vec3* vec3_new_null()
{
    return malloc(sizeof(Vec3));
}

Vec3* vec3_new(vec_t x, vec_t y, vec_t z)
{
    Vec3* newVec3 = vec3_new_null();
    newVec3->x = x;
    newVec3->y = y;
    newVec3->z = z;
    return newVec3;
}

Vec3* vec3_copy(Vec3* vec3)
{
    return vec3_new(vec3->x, vec3->y, vec3->z);
}

void vec3_delete(Vec3** vec3)
{
    free(*vec3);
    (*vec3) = NULL;
}

void vec3_print(Vec3* vec3)
{
#ifdef _CMATH_VEC_LDOUBLE
    printf("{ %Lf %Lf %Lf }\n",vec3->x, vec3->y, vec3->z);
#else
    printf("{ %f %f %f }\n",vec3->x, vec3->y, vec3->z);
#endif
}

void vec3_normalise(Vec3* vec3)
{
    vec_t magnitude = vec3_magnitude(vec3);
    vec3->x /= magnitude;
    vec3->y /= magnitude;
    vec3->z /= magnitude;
}

vec_t vec3_magnitude(Vec3* vec3)
{
    vec_t res = (vec3->x * vec3->x + vec3->y * vec3->y + vec3->z * vec3->z);
#ifdef _CMATH_VEC_DOUBLE 
    res = sqrt(res);
#elif _CMATH_VEC_LDOUBLE 
    res = sqrtl(res);
#else
    res = sqrtf(res);
#endif
    return res;
}

Vec3* vec3_add(Vec3* fVec3, Vec3* sVec3)
{
    return vec3_new(
    (fVec3->x + sVec3->x),
    (fVec3->y + sVec3->y),
    (fVec3->z + sVec3->z));
}

Vec3* vec3_sub(Vec3* fVec3, Vec3* sVec3)
{
    return vec3_new(
    (fVec3->x - sVec3->x),
    (fVec3->y - sVec3->y),
    (fVec3->z - sVec3->z));
}

Vec3* vec3_mult(Vec3* fVec3, Vec3* sVec3)
{
    return vec3_new(
    (fVec3->x * sVec3->x),
    (fVec3->y * sVec3->y),
    (fVec3->z * sVec3->z));
}

Vec3* vec3_mult_scale(Vec3* vec3, vec_t scale)
{
    return vec3_new(
    (vec3->x *= scale),
    (vec3->y *= scale),
    (vec3->z *= scale));
}

Vec3* vec3_div(Vec3* fVec3, Vec3* sVec3)
{
    return vec3_new(
    (fVec3->x / sVec3->x),
    (fVec3->y / sVec3->y),
    (fVec3->z / sVec3->z));
}

Vec3* vec3_pow(Vec3* vec3, int exponent)
{
#ifdef _CMATH_VEC_DOUBLE
    return vec3_new(
    (pow(vec3->x,exponent)), 
    (pow(vec3->y,exponent)),
    (pow(vec3->z,exponent)));
#elif _CMATH_VEC_LDOUBLE
    return vec3_new(
    (powl(vec3->x,exponent)), 
    (powl(vec3->y,exponent)),
    (powl(vec3->z,exponent)));
#else
    return vec3_new(
    (powf(vec3->x,exponent)),
    (powf(vec3->y,exponent)),
    (powf(vec3->z,exponent)));
#endif  
}

vec_t vec3_dot(Vec3* fVec3, Vec3* sVec3)
{
    vec_t x = fVec3->x * sVec3->x;
    vec_t y = fVec3->y * sVec3->y;
    vec_t z = fVec3->z * sVec3->z;
    return x + y + z;
}

vec_t vec3_dot_angle(Vec3* fVec3, Vec3* sVec3, double angle)
{
    vec_t fMag = vec3_magnitude(fVec3);
    vec_t sMag = vec3_magnitude(sVec3);
    return fMag * sMag * cosf(angle);
}

Vec3* vec3_cross(Vec3* fVec3, Vec3* sVec3)
{
    vec_t x = (fVec3->y * sVec3->z) - (fVec3->z * sVec3->y);
    vec_t y = (fVec3->z * sVec3->x) - (fVec3->x * sVec3->z);
    vec_t z = (fVec3->x * sVec3->y) - (fVec3->y * sVec3->x);
    return vec3_new(x,y,z);
}

Vec3* vec3_cross_angle(Vec3* fVec3, Vec3* sVec3, double angle)
{
    Vec3* unitVec3 = vec3_new(1,1,1);
    vec_t fMag = vec3_magnitude(fVec3);
    vec_t sMag = vec3_magnitude(sVec3);
    vec_t scale = fMag * sMag * sin(angle);
    return vec3_mult_scale(unitVec3,scale);
}

int vec3_equal(Vec3* fVec3, Vec3* sVec3)
{
    return (fVec3->x == sVec3->x && fVec3->y == sVec3->y);
}

int vec3_not_equal(Vec3* fVec3, Vec3* sVec3)
{
    return !vec3_equal(fVec3,sVec3);
}

int vec3_greater(Vec3* fVec3, Vec3* sVec3)
{
    return (fVec3->x > sVec3->x && fVec3->y > sVec3->y);
}

int vec3_less(Vec3* fVec3, Vec3* sVec3)
{
    return vec3_greater(sVec3,fVec3);
}

int vec3_greater_equal(Vec3* fVec3, Vec3* sVec3)
{
    return !vec3_less(fVec3,sVec3);
}

int vec3_less_equal(Vec3* fVec3, Vec3* sVec3)
{
    return !vec3_greater(fVec3,sVec3);
}

#else

Vec3 vec3_new_null()
{
    Vec3* newVec3 = malloc(sizeof(newVec3));
    return *newVec3;
}

Vec3 vec3_new(vec_t x, vec_t y, vec_t z)
{
    Vec3* newVec3 = malloc(sizeof(newVec3));
    newVec3->x = x;
    newVec3->y = y;
    newVec3->z = z;
    return *newVec3;
}

Vec3 vec3_copy(Vec3 vec3)
{
    return vec3_new(vec3.x, vec3.y, vec3.z);
}

void vec3_print(Vec3 vec3)
{
#ifdef _CMATH_VEC_LDOUBLE 
    printf("{ %Lf %Lf %Lf }\n",vec3.x, vec3.y, vec3.z);
#else
    printf("{ %f %f %f }\n",vec3.x, vec3.y, vec3.z);
#endif
}

void vec3_normalise(Vec3* vec3)
{
    vec_t magnitude = vec3_magnitude(*vec3);
    vec3->x /= magnitude;
    vec3->y /= magnitude;
    vec3->z /= magnitude;
}

vec_t vec3_magnitude(Vec3 vec3)
{
    vec_t res = (vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
#ifdef _CMATH_VEC_DOUBLE 
    res = sqrt(res);
#elif _CMATH_VEC_LDOUBLE 
    res = sqrtl(res);
#else
    res = sqrtf(res);
#endif
    return res;
}

Vec3 vec3_add(Vec3 fVec3, Vec3 sVec3)
{
    return vec3_new(
    (fVec3.x + sVec3.x),
    (fVec3.y + sVec3.y),
    (fVec3.z + sVec3.z));
}

Vec3 vec3_sub(Vec3 fVec3, Vec3 sVec3)
{
    return vec3_new(
    (fVec3.x - sVec3.x),
    (fVec3.y - sVec3.y),
    (fVec3.z - sVec3.z));
}

Vec3 vec3_mult(Vec3 fVec3, Vec3 sVec3)
{
    return vec3_new(
    (fVec3.x * sVec3.x),
    (fVec3.y * sVec3.y),
    (fVec3.z * sVec3.z));
}

Vec3 vec3_mult_scale(Vec3 vec3, vec_t scale)
{
    return vec3_new(
    (vec3.x *= scale),
    (vec3.y *= scale),
    (vec3.z *= scale));
}

Vec3 vec3_div(Vec3 fVec3, Vec3 sVec3)
{
    return vec3_new(
    (fVec3.x / sVec3.x),
    (fVec3.y / sVec3.y),
    (fVec3.z / sVec3.z));
}

Vec3 vec3_pow(Vec3 vec3, int exponent)
{
#ifdef _CMATH_VEC_DOUBLE
    return vec3_new(
    (pow(vec3.x,exponent)), 
    (pow(vec3.y,exponent)),
    (pow(vec3.z,exponent)));
#elif _CMATH_VEC_LDOUBLE
    return vec3_new(
    (powl(vec3.x,exponent)), 
    (powl(vec3.y,exponent)),
    (powl(vec3.z,exponent)));
#else
    return vec3_new(
    (powf(vec3.x,exponent)),
    (powf(vec3.y,exponent)),
    (powf(vec3.z,exponent)));
#endif  
}

vec_t vec3_dot(Vec3 fVec3, Vec3 sVec3)
{
    vec_t x = fVec3.x * sVec3.x;
    vec_t y = fVec3.y * sVec3.y;
    vec_t z = fVec3.z * sVec3.z;
    return x + y + z;
}

vec_t vec3_dot_angle(Vec3 fVec3, Vec3 sVec3, double angle)
{
    vec_t fMag = vec3_magnitude(fVec3);
    vec_t sMag = vec3_magnitude(sVec3);
    return fMag * sMag * cosf(angle);
}

Vec3 vec3_cross(Vec3 fVec3, Vec3 sVec3)
{
    vec_t x = (fVec3.y * sVec3.z) - (fVec3.z * sVec3.y);
    vec_t y = (fVec3.z * sVec3.x) - (fVec3.x * sVec3.z);
    vec_t z = (fVec3.x * sVec3.y) - (fVec3.y * sVec3.x);
    return vec3_new(x,y,z);
}

Vec3 vec3_cross_angle(Vec3 fVec3, Vec3 sVec3, double angle)
{
    Vec3 unitVec3 = vec3_new(1,1,1);
    vec_t fMag = vec3_magnitude(fVec3);
    vec_t sMag = vec3_magnitude(sVec3);
    vec_t scale = fMag * sMag * sin(angle);
    return vec3_mult_scale(unitVec3,scale);
}

int vec3_equal(Vec3 fVec3, Vec3 sVec3)
{
    return (fVec3.x == sVec3.x && fVec3.y == sVec3.y);
}

int vec3_not_equal(Vec3 fVec3, Vec3 sVec3)
{
    return !vec3_equal(fVec3,sVec3);
}

int vec3_greater(Vec3 fVec3, Vec3 sVec3)
{
    return (fVec3.x > sVec3.x && fVec3.y > sVec3.y);
}

int vec3_less(Vec3 fVec3, Vec3 sVec3)
{
    return vec3_greater(sVec3,fVec3);
}

int vec3_greater_equal(Vec3 fVec3, Vec3 sVec3)
{
    return !vec3_less(fVec3,sVec3);
}

int vec3_less_equal(Vec3 fVec3, Vec3 sVec3)
{
    return !vec3_greater(fVec3,sVec3);
}

#endif

