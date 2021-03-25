#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mat2.h"

#ifdef _CMATH_MAT_USE_POINTER

Mat2* mat2_new_null()
{
    return malloc(sizeof(Mat2));
}

Mat2* mat2_new(mat_t m11, mat_t m12, mat_t m21, mat_t m22)
{
    Mat2* newMat2 = malloc(sizeof(Mat2));
    newMat2->data[0] = m11;
    newMat2->data[1] = m12;
    newMat2->data[2] = m21;
    newMat2->data[3] = m22;
    return newMat2;
}

Mat2* mat2_new_array(mat_t* data)
{
    return mat2_new(data[0],data[1],data[2], data[3]);
}

Mat2* mat2_copy(Mat2* mat2)
{   
    return mat2_new_array(mat2->data);
}

void mat2_print(Mat2* mat2)
{
#ifdef _CMATH_MAT_LDOUBLE
    printf("[ %Lf %Lf ]\n",mat2->data[0], mat2->data[1]);
    printf("[ %Lf %Lf ]\n",mat2->data[2], mat2->data[3]);
#else
    printf("[ %f %f ]\n",mat2->data[0], mat2->data[1]);
    printf("[ %f %f ]\n",mat2->data[2], mat2->data[3]);
#endif
}

Mat2* mat2_add(Mat2* fMat2, Mat2* sMat2)
{
    return mat2_new(
    (fMat2->data[0] + sMat2->data[0]),
    (fMat2->data[1] + sMat2->data[1]),
    (fMat2->data[2] + sMat2->data[2]),
    (fMat2->data[3] + sMat2->data[3]));
}

Mat2* mat2_sub(Mat2* fMat2, Mat2* sMat2)
{
    return mat2_new(
    (fMat2->data[0] - sMat2->data[0]),
    (fMat2->data[1] - sMat2->data[1]),
    (fMat2->data[2] - sMat2->data[2]),
    (fMat2->data[3] - sMat2->data[3]));
}

Mat2* mat2_mult(Mat2* fMat2, Mat2* sMat2)
{
    mat_t m11 = fMat2->data[0] * sMat2->data[0] + fMat2->data[1] * sMat2->data[2];
    mat_t m12 = fMat2->data[0] * sMat2->data[1] + fMat2->data[1] * sMat2->data[3];
    mat_t m21 = fMat2->data[2] * sMat2->data[0] + fMat2->data[3] * sMat2->data[2];
    mat_t m22 = fMat2->data[2] * sMat2->data[1] + fMat2->data[3] * sMat2->data[3];
    return mat2_new(m11,m12,m21,m22);
}

Mat2* mat2_scale(Mat2* mat2, mat_t scale)
{
    return mat2_new(
    (mat2->data[0] * scale),
    (mat2->data[1] * scale),
    (mat2->data[2] * scale),
    (mat2->data[3] * scale));
}

mat_t mat2_trace(Mat2* mat2)
{
    return mat2->data[0] + mat2->data[3];
}

mat_t mat2_sum(Mat2* mat2)
{
    return mat2->data[0] + mat2->data[1] + mat2->data[2] + mat2->data[3];
}

mat_t mat2_determinant(Mat2* mat2)
{
    return (mat2->data[0] * mat2->data[3] - mat2->data[1] * mat2->data[2]);
}

Mat2* mat2_inverse(Mat2* mat2)
{
    //add in compatibility for long doubles, doubles and floats.
    mat_t scale = 1.0000000f / mat2_determinant(mat2);
    return mat2_scale(mat2,scale);
}

Mat2* mat2_negative(Mat2* mat2)
{
    return mat2_new(
    (mat2->data[0] * -1),
    (mat2->data[1] * -1),
    (mat2->data[2] * -1),
    (mat2->data[3] * -1));
}

Mat2* mat2_transpose(Mat2* mat2)
{
    return mat2_new(
    (mat2->data[0]),
    (mat2->data[2]),
    (mat2->data[1]),
    (mat2->data[3]));
}

int mat2_equal(Mat2* fMat2, Mat2* sMat2)
{
    int equals = 
    fMat2->data[0] == sMat2->data[0] &&
    fMat2->data[1] == sMat2->data[1] &&
    fMat2->data[2] == sMat2->data[2] &&
    fMat2->data[3] == sMat2->data[3];
    return equals;
}

int mat2_not_equal(Mat2* fMat2, Mat2* sMat2)
{
    return !mat2_equal(fMat2,sMat2);
}

int mat2_greater(Mat2* fMat2, Mat2* sMat2)
{
    int equals = 
    fMat2->data[0] > sMat2->data[0] &&
    fMat2->data[1] > sMat2->data[1] &&
    fMat2->data[2] > sMat2->data[2] &&
    fMat2->data[3] > sMat2->data[3];
    return equals;
}

int mat2_less(Mat2* fMat2, Mat2* sMat2)
{
    return mat2_greater(sMat2, fMat2);
}

int mat2_greater_equal(Mat2* fMat2, Mat2* sMat2)
{
    return !mat2_less(fMat2, sMat2);
}

int mat2_less_equal(Mat2* fMat2, Mat2* sMat2)
{
    return !mat2_greater(fMat2, sMat2);
}

#else

Mat2 mat2_new_null()
{
    Mat2* newMat2 = malloc(sizeof(Mat2));
    return *newMat2;
}

Mat2 mat2_new(mat_t m11, mat_t m12, mat_t m21, mat_t m22)
{
    Mat2* newMat2 = malloc(sizeof(Mat2));
    newMat2->data[0]= m11;
    newMat2->data[1] = m12;
    newMat2->data[2] = m21;
    newMat2->data[3] = m22;
    return *newMat2;
}

Mat2 mat2_new_array(mat_t* data)
{
    return mat2_new(data[0],data[1],data[2], data[3]);
}

Mat2 mat2_copy(Mat2 mat2)
{   
    return mat2_new_array(mat2.data);
}

void mat2_delete(Mat2* mat2) 
{
    free(mat2);
    mat2 = NULL;
}

void mat2_print(Mat2 mat2)
{
#ifdef _CMATH_MAT_LDOUBLE
    printf("[ %Lf %Lf ]\n",mat2.data[0], mat2.data[1]);
    printf("[ %Lf %Lf ]\n",mat2.data[2  ], mat2.data[3]);
#else
    printf("[ %f %f ]\n",mat2.data[0], mat2.data[1]);
    printf("[ %f %f ]\n",mat2.data[2], mat2.data[3]);
#endif
}

Mat2 mat2_add(Mat2 fMat2, Mat2 sMat2)
{
    return mat2_new(
    (fMat2.data[0] + sMat2.data[0]),
    (fMat2.data[1] + sMat2.data[1]),
    (fMat2.data[2] + sMat2.data[2]),
    (fMat2.data[3] + sMat2.data[3]));
}

Mat2 mat2_sub(Mat2 fMat2, Mat2 sMat2)
{
    return mat2_new(
    (fMat2.data[0] - sMat2.data[0]),
    (fMat2.data[1] - sMat2.data[1]),
    (fMat2.data[2] - sMat2.data[2]),
    (fMat2.data[3] - sMat2.data[3]));
}

Mat2 mat2_mult(Mat2 fMat2, Mat2 sMat2)
{
    mat_t m11 = fMat2.data[0] * sMat2.data[0] + fMat2.data[1] * sMat2.data[2];
    mat_t m12 = fMat2.data[0] * sMat2.data[1] + fMat2.data[1] * sMat2.data[3];
    mat_t m21 = fMat2.data[2] * sMat2.data[0] + fMat2.data[3] * sMat2.data[2];
    mat_t m22 = fMat2.data[2] * sMat2.data[1] + fMat2.data[3] * sMat2.data[3];
    return mat2_new(m11,m12,m21,m22);
}

Mat2 mat2_scale(Mat2 mat2, mat_t scale)
{
    return mat2_new(
    (mat2.data[0] * scale),
    (mat2.data[1] * scale),
    (mat2.data[2] * scale),
    (mat2.data[3] * scale));
}

mat_t mat2_trace(Mat2 mat2)
{
    return mat2.data[0] + mat2.data[2];
}

mat_t mat2_sum(Mat2 mat2)
{
    return mat2.data[0] + mat2.data[1] + mat2.data[2] + mat2.data[3];
}

mat_t mat2_determinant(Mat2 mat2)
{
    return (mat2.data[0] * mat2.data[3] - mat2.data[1] * mat2.data[2]);
}

Mat2 mat2_inverse(Mat2 mat2)
{
    //add in compatibility for long doubles, doubles and floats.
    mat_t scale = 1.0000000f / mat2_determinant(mat2);
    return mat2_scale(mat2,scale);
}

Mat2 mat2_negative(Mat2 mat2)
{
    return mat2_new(
    (mat2.data[0] * -1),
    (mat2.data[1] * -1),
    (mat2.data[2] * -1),
    (mat2.data[3] * -1));
}

Mat2 mat2_transpose(Mat2 mat2)
{
    return mat2_new(
    (mat2.data[0]),
    (mat2.data[1]),
    (mat2.data[2]),
    (mat2.data[3]));
}

int mat2_equal(Mat2 fMat2, Mat2 sMat2)
{
    int equals = 
    fMat2.data[0] == sMat2.data[0] &&
    fMat2.data[1] == sMat2.data[1] &&
    fMat2.data[2] == sMat2.data[2] &&
    fMat2.data[3] == sMat2.data[3];
    return equals;
}

int mat2_not_equal(Mat2 fMat2, Mat2 sMat2)
{
    return !mat2_equal(fMat2,sMat2);
}

int mat2_greater(Mat2 fMat2, Mat2 sMat2)
{
    int equals = 
    fMat2.data[0] > sMat2.data[0] &&
    fMat2.data[1] > sMat2.data[1] &&
    fMat2.data[2] > sMat2.data[2] &&
    fMat2.data[3] > sMat2.data[3];
    return equals;
}

int mat2_less(Mat2 fMat2, Mat2 sMat2)
{
    return mat2_greater(sMat2, fMat2);
}

int mat2_greater_equal(Mat2 fMat2, Mat2 sMat2)
{
    return !mat2_less(fMat2, sMat2);
}

int mat2_less_equal(Mat2 fMat2, Mat2 sMat2)
{
    return !mat2_greater(fMat2, sMat2);
}

#endif

void mat2_assign(Mat2* dest, const Mat2* src)
{
    dest->data[0] = src->data[0];
    dest->data[1] = src->data[1];
    dest->data[2] = src->data[2];
    dest->data[3] = src->data[3];
}