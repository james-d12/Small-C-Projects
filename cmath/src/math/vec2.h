#ifndef _CMATH_VEC2_H
#define _CMATH_VEC2_H

#include "../core.h"

#ifdef _CMATH_VEC_USE_UNION
typedef union Vec2
{
    struct { vec_t x; vec_t y; };
    vec_t coord[2];
}Vec2;
#else
typedef struct Vec2
{
    vec_t x,y;
}Vec2;
#endif 

#ifdef _CMATH_VEC_USE_POINTER

Vec2* vec2_new_null();
Vec2* vec2_new(vec_t x, vec_t y);
Vec2* vec2_copy(Vec2* vec2);
void  vec2_delete(Vec2** vec2);
void  vec2_print(Vec2* vec2);

void  vec2_normalise(Vec2* vec2);
vec_t vec2_magnitude(Vec2* vec2);

Vec2* vec2_add(Vec2* fVec2, Vec2* sVec2);
Vec2* vec2_sub(Vec2* fVec2, Vec2* sVec2);
Vec2* vec2_mult(Vec2* fVec2, Vec2* sVec2);
Vec2* vec2_scale(Vec2* vec2, vec_t scale);
Vec2* vec2_div(Vec2* fVec2, Vec2* sVec2);
Vec2* vec2_pow(Vec2* vec2, int exponent);

vec_t vec2_dot(Vec2* fVec2, Vec2* sVec2);
vec_t vec2_dot_angle(Vec2* fVec2, Vec2* sVec2, double angle);

//add vec2 transformations with matrices

int  vec2_equal(Vec2* fVec2, Vec2* sVec2);
int  vec2_not_equal(Vec2* fVec2, Vec2* sVec2);
int  vec2_greater(Vec2* fVec2, Vec2* sVec2);
int  vec2_less(Vec2* fVec2, Vec2* sVec2);
int  vec2_greater_equal(Vec2* fVec2, Vec2* sVec2);
int  vec2_less_equal(Vec2* fVec2, Vec2* sVec2);

#else

Vec2 vec2_new_null();
Vec2 vec2_new(vec_t x, vec_t y);
Vec2 vec2_copy(Vec2 vec2);
void vec2_print(Vec2 vec2);

Vec2  vec2_normalise(Vec2 vec2);
vec_t vec2_magnitude(Vec2 vec2);

Vec2 vec2_add(Vec2 fVec2, Vec2 sVec2);
Vec2 vec2_sub(Vec2 fVec2, Vec2 sVec2);
Vec2 vec2_mult(Vec2 fVec2, Vec2 sVec2);
Vec2 vec2_scale(Vec2 vec2, vec_t scale);
Vec2 vec2_div(Vec2 fVec2, Vec2 sVec2);
Vec2 vec2_pow(Vec2 vec2, int exponent);

vec_t vec2_dot(Vec2 fVec2, Vec2 sVec2);
vec_t vec2_dot_angle(Vec2 fVec2, Vec2 sVec2, double angle);

int  vec2_equal(Vec2 fVec2, Vec2 sVec2);
int  vec2_not_equal(Vec2 fVec2, Vec2 sVec2);
int  vec2_greater(Vec2 fVec2, Vec2 sVec2);
int  vec2_less(Vec2 fVec2, Vec2 sVec2);
int  vec2_greater_equal(Vec2 fVec2, Vec2 sVec2);
int  vec2_less_equal(Vec2 fVec2, Vec2 sVec2);

#endif

void vec2_assign(Vec2* dest, const Vec2* src);

#endif