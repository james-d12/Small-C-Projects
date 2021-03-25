#ifndef _CMATH_MAT2_H
#define _CMATH_MAT2_H

#include "../core.h"

#ifdef _CMATH_MAT_USE_UNION
typedef union Mat2
{
    struct 
    {    
        mat_t m11;
        mat_t m12;
        mat_t m21;
        mat_t m22;
    };
    mat_t data[4];
}Mat2;
#else
typedef struct Mat2
{
    mat_t data[4];
}Mat2;
#endif 

#ifdef _CMATH_MAT_USE_POINTER

Mat2* mat2_new_null();
Mat2* mat2_new(mat_t _m11, mat_t m12, mat_t m21, mat_t m22);
Mat2* mat2_new_array(mat_t* data);

Mat2* mat2_copy(Mat2* mat2);

void  mat2_delete(Mat2** mat2);
void  mat2_print(Mat2* mat2);

Mat2* mat2_add(Mat2* fMat2, Mat2* sMat2);
Mat2* mat2_sub(Mat2* fMat2, Mat2* sMat2);
Mat2* mat2_mult(Mat2* fMat2, Mat2* sMat2);
Mat2* mat2_scale(Mat2* mat2, mat_t scale);

mat_t mat2_trace(Mat2* mat2);
mat_t mat2_sum(Mat2* mat2);

mat_t mat2_determinant(Mat2* mat2);
Mat2* mat2_inverse(Mat2* mat2);
Mat2* mat2_negative(Mat2* mat2);
Mat2* mat2_transpose(Mat2* mat2);

int mat2_equal(Mat2* fMat2, Mat2* sMat2);
int mat2_not_equal(Mat2* fMat2, Mat2* sMat2);
int mat2_greater(Mat2* fMat2, Mat2* sMat2);
int mat2_less(Mat2* fMat2, Mat2* sMat2);
int mat2_greater_equal(Mat2* fMat2, Mat2* sMat2);
int mat2_less_equal(Mat2* fMat2, Mat2* sMat2);

#else

Mat2 mat2_new_null();
Mat2 mat2_new(mat_t _m11, mat_t m12, mat_t m21, mat_t m22);
Mat2 mat2_new_array(mat_t* data);

Mat2 mat2_copy(Mat2 mat2);

void mat2_delete(Mat2* mat2);
void mat2_print(Mat2 mat2);

Mat2 mat2_add(Mat2 fMat2, Mat2 sMat2);
Mat2 mat2_sub(Mat2 fMat2, Mat2 sMat2);
Mat2 mat2_mult(Mat2 fMat2, Mat2 sMat2);
Mat2 mat2_scale(Mat2 mat2, mat_t scale);

mat_t mat2_trace(Mat2 mat2);
mat_t mat2_sum(Mat2 mat2);

mat_t mat2_determinant(Mat2 mat2);
Mat2  mat2_inverse(Mat2 mat2);
Mat2  mat2_negative(Mat2 mat2);
Mat2  mat2_transpose(Mat2 mat2);

int mat2_equal(Mat2 fMat2, Mat2 sMat2);
int mat2_not_equal(Mat2 fMat2, Mat2 sMat2);
int mat2_greater(Mat2 fMat2, Mat2 sMat2);
int mat2_less(Mat2 fMat2, Mat2 sMat2);
int mat2_greater_equal(Mat2 fMat2, Mat2 sMat2);
int mat2_less_equal(Mat2 fMat2, Mat2 sMat2);

#endif

void mat2_assign(Mat2* dest, const Mat2* src);

#endif