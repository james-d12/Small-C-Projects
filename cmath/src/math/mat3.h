#ifndef _CMATH_MAT3_H
#define _CMATH_MAT3_H

#include "../core.h"

#ifdef _CMATH_MAT_USE_UNION
typedef union Mat3
{
    struct 
    {    
        mat_t m11;
        mat_t m12;
        mat_t m13;
        mat_t m21;
        mat_t m22;
        mat_t m23;
        mat_t m31;
        mat_t m32;
        mat_t m33;
    };
    mat_t data[9];
}Mat3;
#else
typedef struct Mat3
{
    mat_t data[9];
}Mat3;
#endif

#ifdef _CMATH_MAT_USE_POINTER

Mat3* mat3_new_null();
Mat3* mat3_new(mat_t m11, mat_t m12, mat_t m13,
               mat_t m21, mat_t m22, mat_t m23,
               mat_t m31, mat_t m32, mat_t m33);
Mat3* mat3_new_array(mat_t* data);

Mat3* mat3_copy(Mat3* mat3);

void mat3_delete(Mat3** mat3);
void mat3_print(Mat3* mat3);

Mat3* mat3_add(Mat3* fMat3, Mat3* sMat3);
Mat3* mat3_sub(Mat3* fMat3, Mat3* sMat3);
Mat3* mat3_mult(Mat3* fMat3, Mat3* sMat3);
Mat3* mat3_scale(Mat3* mat3, mat_t scale);

mat_t mat3_trace(Mat3* mat3);
mat_t mat3_sum(Mat3* mat3);

mat_t mat3_determinant(Mat3* mat3);
Mat3* mat3_inverse(Mat3* mat3);
Mat3* mat3_negative(Mat3* mat3);
Mat3* mat3_transpose(Mat3* mat3);

int mat3_equal(Mat3* fMat3, Mat3* sMat3);
int mat3_not_equal(Mat3* fMat3, Mat3* sMat3);
int mat3_greater(Mat3* fMat3, Mat3* sMat3);
int mat3_less(Mat3* fMat3, Mat3* sMat3);
int mat3_greater_equal(Mat3* fMat3, Mat3* sMat3);
int mat3_less_equal(Mat3* fMat3, Mat3* sMat3);

#else

Mat3 mat3_new_null();
Mat3 mat3_new(mat_t m11, mat_t m12, mat_t m13,
               mat_t m21, mat_t m22, mat_t m23,
               mat_t m31, mat_t m32, mat_t m33);
Mat3 mat3_new_array(mat_t* data);

void mat3_print(Mat3 mat3);

Mat3 mat3_add(Mat3 fMat3, Mat3 sMat3);
Mat3 mat3_sub(Mat3 fMat3, Mat3 sMat3);
Mat3 mat3_mult(Mat3 fMat3, Mat3 sMat3);
Mat3 mat3_scale(Mat3 mat3, mat_t scale);

mat_t mat3_trace(Mat3 mat3);
mat_t mat3_sum(Mat3 mat3);

mat_t mat3_determinant(Mat3 mat3);
Mat3  mat3_inverse(Mat3 mat3);
Mat3  mat3_negative(Mat3 mat3);
Mat3  mat3_tranpose(Mat3 mat3);

int mat3_equal(Mat3 fMat3, Mat3 sMat3);
int mat3_not_equal(Mat3 fMat3, Mat3 sMat3);
int mat3_greater(Mat3 fMat3, Mat3 sMat3);
int mat3_less(Mat3 fMat3, Mat3 sMat3);
int mat3_greater_equal(Mat3 fMat3, Mat3 sMat3);
int mat3_less_equal(Mat3 fMat3, Mat3 sMat3);

#endif

#endif