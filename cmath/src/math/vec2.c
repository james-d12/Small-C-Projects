#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vec2.h"

#ifdef _CMATH_VEC_USE_POINTER 

Vec2* vec2_new_null()
{
    return malloc(sizeof(Vec2));
}

Vec2* vec2_new(vec_t x, vec_t y)
{
    Vec2* newVec2 = vec2_new_null();
    newVec2->x = x;
    newVec2->y = y;
    return newVec2;
}

Vec2* vec2_copy(Vec2* vec2)
{
    return vec2_new(vec2->x, vec2->y);
}

void vec2_delete(Vec2** vec2)
{
    free(*vec2);
    (*vec2) = NULL;
}

void vec2_print(Vec2* vec2)
{
#ifdef _CMATH_VEC_LDOUBLE 
    printf("{ %Lf %Lf }\n",vec2->x, vec2->y);
#else
    printf("{ %f %f }\n",vec2->x, vec2->y);
#endif
}

void vec2_normalise(Vec2* vec2)
{
    vec_t magnitude = vec2_magnitude(vec2);
    vec2->x /= magnitude;
    vec2->y /= magnitude;
}

vec_t vec2_magnitude(Vec2* vec2)
{
    vec_t res = (vec2->x * vec2->x + vec2->y * vec2->y);
#ifdef _CMATH_VEC_DOUBLE 
    res = sqrt(res);
#elif _CMATH_VEC_LDOUBLE 
    res = sqrtl(res);
#else
    res = sqrtf(res);
#endif
    return res;
}

Vec2* vec2_add(Vec2* fVec2, Vec2* sVec2) 
{ 
    return vec2_new(
    (fVec2->x + sVec2->x),
    (fVec2->y + sVec2->y)); 
}

Vec2* vec2_sub(Vec2* fVec2, Vec2* sVec2) 
{ 
    return vec2_new(
    (fVec2->x - sVec2->x),
    (fVec2->y - sVec2->y));  
}

Vec2* vec2_mult(Vec2* fVec2, Vec2* sVec2) 
{ 
    return vec2_new(
    (fVec2->x * sVec2->x),
    (fVec2->y * sVec2->y));  
}

Vec2* vec2_scale(Vec2* vec2, vec_t scale) 
{ 
    return vec2_new(
    (vec2->x * scale),
    (vec2->y * scale));  
}

Vec2* vec2_mult_div(Vec2* fVec2, Vec2* sVec2) 
{ 
    return vec2_new(
    (fVec2->x / sVec2->x),
    (fVec2->y / sVec2->y));  
}

Vec2* vec2_pow(Vec2* vec2, int exponent)
{
#ifdef _CMATH_VEC_DOUBLE
    return vec2_new((pow(vec2->x,exponent)), (pow(vec2->y,exponent)));
#elif _CMATH_VEC_LDOUBLE
    return vec2_new((powl(vec2->x,exponent)), (powl(vec2->y,exponent)));
#else
    return vec2_new((powf(vec2->x,exponent)), (powf(vec2->y,exponent)));
#endif
}

vec_t vec2_dot(Vec2* fVec2, Vec2* sVec2)
{
    vec_t x = fVec2->x * sVec2->x;
    vec_t y = fVec2->y * sVec2->y;
    return x + y;
}

vec_t vec2_dot_angle(Vec2* fVec2, Vec2* sVec2, double angle)
{
    vec_t fMag = vec2_magnitude(fVec2);
    vec_t sMag = vec2_magnitude(sVec2);
    return fMag* sMag * cosf(angle);
}

int vec2_equal(Vec2* fVec2, Vec2* sVec2)
{
    return (fVec2->x == sVec2->x && fVec2->y == sVec2->y);
}

int vec2_not_equal(Vec2* fVec2, Vec2* sVec2)
{
    return !vec2_equal(fVec2,sVec2);
}

int vec2_greater(Vec2* fVec2, Vec2* sVec2)
{
    return (fVec2->x > sVec2->x && fVec2->y > sVec2->y);
}

int vec2_less(Vec2* fVec2, Vec2* sVec2)
{
    return vec2_greater(sVec2,fVec2);
}

int vec2_greater_equal(Vec2* fVec2, Vec2* sVec2)
{
    return !vec2_less(fVec2,sVec2);
}

int vec2_less_equal(Vec2* fVec2, Vec2* sVec2)
{
    return !vec2_greater(fVec2,sVec2);
}

#else

Vec2 vec2_new_null()
{
    Vec2* newVec2 = malloc(sizeof(newVec2));
    return *newVec2;
}

Vec2 vec2_new(vec_t x, vec_t y)
{
    Vec2* newVec2 = malloc(sizeof(newVec2));
    newVec2->x = x;
    newVec2->y = y;
    return *newVec2;
}

Vec2 vec2_copy(Vec2 vec2)
{
    return vec2_new(vec2.x, vec2.y);
}

void vec2_print(Vec2 vec2)
{
#ifdef _CMATH_VEC_LDOUBLE
    printf("{ %Lf %Lf }\n",vec2.x, vec2.y);
#else
    printf("{ %f %f }\n",vec2.x, vec2.y);
#endif
}

Vec2 vec2_normalise(Vec2 vec2)
{
    vec_t magnitude = vec2_magnitude(vec2);
    vec_t x = vec2.x / magnitude;
    vec_t y = vec2.y / magnitude;
    return vec2_new(x,y);
}

vec_t vec2_magnitude(Vec2 vec2)
{
    vec_t res = (vec2.x * vec2.x + vec2.y * vec2.y);
#ifdef _CMATH_VEC_DOUBLE
    res = sqrt(res);
#elif _CMATH_VEC_LDOUBLE
    res = sqrtl(res);
#else
    res = sqrtf(res);
#endif
    return res;
}

Vec2 vec2_add(Vec2 fVec2, Vec2 sVec2) 
{ 
    return vec2_new((fVec2.x + sVec2.x),(fVec2.y + sVec2.y)); 
}

Vec2 vec2_sub(Vec2 fVec2, Vec2 sVec2) 
{ 
    return vec2_new((fVec2.x - sVec2.x),(fVec2.y - sVec2.y));  
}

Vec2 vec2_mult(Vec2 fVec2, Vec2 sVec2) 
{ 
    return vec2_new((fVec2.x * sVec2.x),(fVec2.y * sVec2.y));  
}

Vec2 vec2_scale(Vec2 vec2, vec_t scale) 
{ 
    return vec2_new((vec2.x * scale),(vec2.y * scale));  
}

Vec2 vec2_mult_div(Vec2 fVec2, Vec2 sVec2) 
{ 
    return vec2_new((fVec2.x / sVec2.x),(fVec2.y / sVec2.y));  
}

Vec2 vec2_pow(Vec2 vec2, int exponent)
{
#ifdef _CMATH_VEC_DOUBLE
    return vec2_new((pow(vec2.x,exponent)), (pow(vec2.y,exponent)));
#elif _CMATH_VEC_LDOUBLE
    return vec2_new((powl(vec2.x,exponent)), (powl(vec2.y,exponent)));
#else
    return vec2_new((powf(vec2.x,exponent)), (powf(vec2.y,exponent)));
#endif
}

vec_t vec2_dot(Vec2 fVec2, Vec2 sVec2)
{
    vec_t x = fVec2.x * sVec2.x;
    vec_t y = fVec2.y * sVec2.y;
    return x + y;
}

vec_t vec2_dot_angle(Vec2 fVec2, Vec2 sVec2, double angle)
{
    vec_t fMag = vec2_magnitude(fVec2);
    vec_t sMag = vec2_magnitude(sVec2);
    return fMag* sMag * cosf(angle);
}

int vec2_equal(Vec2 fVec2, Vec2 sVec2)
{
    return (fVec2.x == sVec2.x && fVec2.y == sVec2.y);
}

int vec2_not_equal(Vec2 fVec2, Vec2 sVec2)
{
    return !vec2_equal(fVec2,sVec2);
}

int vec2_greater(Vec2 fVec2, Vec2 sVec2)
{
    return (fVec2.x > sVec2.x && fVec2.y > sVec2.y);
}

int vec2_less(Vec2 fVec2, Vec2 sVec2)
{
    return vec2_greater(sVec2,fVec2);
}

int vec2_greater_equal(Vec2 fVec2, Vec2 sVec2)
{
    return !vec2_less(fVec2,sVec2);
}

int vec2_less_equal(Vec2 fVec2, Vec2 sVec2)
{
    return !vec2_greater(fVec2,sVec2);
}

#endif

void vec2_assign(Vec2* dest, const Vec2* src)
{
    dest->x = src->x;
    dest->y = src->y;
}
