#ifndef _CMATH_VEC3_H
#define _CMATH_VEC3_H

#include "../core.h"

#ifdef _CMATH_VEC_USE_UNION
typedef union Vec3
{
    struct { vec_t x; vec_t y; vec_t z; };
    vec_t coord[3];
}Vec3;
#else
typedef struct Vec3
{
    vec_t x,y,z;
}Vec3;
#endif 

#ifdef _CMATH_VEC_USE_POINTER

Vec3* vec3_new_null();
Vec3* vec3_new(vec_t x, vec_t y, vec_t z);
Vec3* vec3_copy(Vec3* vec3);
void  vec3_delete(Vec3** vec3);
void  vec3_print(Vec3* vec3);

void vec3_normalise(Vec3* vec3);
vec_t vec3_magnitude(Vec3* vec3);

Vec3* vec3_add(Vec3* fVec3, Vec3* sVec3);
Vec3* vec3_sub(Vec3* fVec3, Vec3* sVec3);
Vec3* vec3_mult(Vec3* fVec3, Vec3* sVec3);
Vec3* vec3_scale(Vec3* vec3, vec_t scale);
Vec3* vec3_div(Vec3* fVec3, Vec3* sVec3);
Vec3* vec3_pow(Vec3* vec3, int exponent);

vec_t vec3_dot(Vec3* fVec3, Vec3* sVec3);
vec_t vec3_dot_angle(Vec3* fVec3, Vec3* sVec3, double angle);
Vec3* vec3_cross(Vec3* fVec3, Vec3* sVec3);
Vec3* vec3_cross_angle(Vec3* fVec3, Vec3* sVec3, double angle);

int vec3_equal(Vec3* fVec3, Vec3* sVec3);
int vec3_not_equal(Vec3* fVec3, Vec3* sVec3);
int vec3_greater(Vec3* fVec3, Vec3* sVec3);
int vec3_less(Vec3* fVec3, Vec3* sVec3);
int vec3_greater_equal(Vec3* fVec3, Vec3* sVec3);
int vec3_less_equal(Vec3* fVec3, Vec3* sVec3);

#else

Vec3 vec3_new_null();
Vec3 vec3_new(vec_t x, vec_t y, vec_t z);
Vec3 vec3_copy(Vec3 vec3);
void vec3_print(Vec3 vec3);

void  vec3_normalise(Vec3* vec3);
vec_t vec3_magnitude(Vec3 vec3);

Vec3 vec3_add(Vec3 fVec3, Vec3 sVec3);
Vec3 vec3_sub(Vec3 fVec3, Vec3 sVec3);
Vec3 vec3_mult(Vec3 fVec3, Vec3 sVec3);
Vec3 vec3_scale(Vec3 vec3, vec_t scale);
Vec3 vec3_div(Vec3 fVec3, Vec3 sVec3);
Vec3 vec3_pow(Vec3 vec3, int exponent);

vec_t vec3_dot(Vec3 fVec3, Vec3 sVec3);
vec_t vec3_dot_angle(Vec3 fVec3, Vec3 sVec3, double angle);
Vec3 vec3_cross(Vec3 fVec3, Vec3 sVec3);
Vec3 vec3_cross_angle(Vec3 fVec3, Vec3 sVec3, double angle);

int vec3_equal(Vec3 fVec3, Vec3 sVec3);
int vec3_not_equal(Vec3 fVec3, Vec3 sVec3);
int vec3_greater(Vec3 fVec3, Vec3 sVec3);
int vec3_less(Vec3 fVec3, Vec3 sVec3);
int vec3_greater_equal(Vec3 fVec3, Vec3 sVec3);
int vec3_less_equal(Vec3 fVec3, Vec3 sVec3);

#endif
#endif