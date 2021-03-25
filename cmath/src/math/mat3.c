#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mat3.h"

#ifdef _CMATH_MAT_USE_POINTER

Mat3* mat3_new_null()
{
    return malloc(sizeof(Mat3));
}

Mat3* mat3_new(mat_t m11, mat_t m12, mat_t m13,
               mat_t m21, mat_t m22, mat_t m23,
               mat_t m31, mat_t m32, mat_t m33)
{
    Mat3* newMat3 = malloc(sizeof(Mat3));
    newMat3->data[0] = m11;
    newMat3->data[1] = m12;
    newMat3->data[2] = m13;
    newMat3->data[3] = m21;
    newMat3->data[4] = m22;
    newMat3->data[5] = m23;
    newMat3->data[6] = m31;
    newMat3->data[7] = m32;
    newMat3->data[8] = m33;
    return newMat3;
}

Mat3* mat3_new_array(mat_t* data)
{
    return mat3_new(
    data[0],data[1],data[2],
    data[3],data[4],data[5],
    data[6],data[7],data[8]);
}

Mat3* mat3_copy(Mat3* mat3)
{
    return mat3_new_array(mat3->data);
}

void mat3_delete(Mat3** mat3)
{
    free(*mat3);
    (*mat3) = NULL;
}

void mat3_print(Mat3* mat3)
{
#ifdef _CMATH_MAT_LDOUBLE
    printf("[ %Lf %Lf %Lf ]\n",mat3->data[0], mat3->data[1], mat3->data[2]);
    printf("[ %Lf %Lf %Lf ]\n",mat3->data[3], mat3->data[4], mat3->data[5]);
    printf("[ %Lf %Lf %Lf ]\n",mat3->data[6], mat3->data[7], mat3->data[8]);
#else
    printf("[ %f %f %f ]\n",mat3->data[0], mat3->data[1], mat3->data[2]);
    printf("[ %f %f %f ]\n",mat3->data[3], mat3->data[4], mat3->data[5]);
    printf("[ %f %f %f ]\n",mat3->data[6], mat3->data[7], mat3->data[8]);
#endif
}

Mat3* mat3_add(Mat3* fMat3, Mat3* sMat3)
{
    return mat3_new(
    (fMat3->data[0] + sMat3->data[0]),
    (fMat3->data[1] + sMat3->data[1]),
    (fMat3->data[2] + sMat3->data[2]),
    (fMat3->data[3] + sMat3->data[3]),
    (fMat3->data[4] + sMat3->data[4]),
    (fMat3->data[5] + sMat3->data[5]),
    (fMat3->data[6] + sMat3->data[6]),
    (fMat3->data[7] + sMat3->data[7]),
    (fMat3->data[8] + sMat3->data[8]));
}

Mat3* mat3_sub(Mat3* fMat3, Mat3* sMat3)
{
    return mat3_new(
    (fMat3->data[0] - sMat3->data[0]),
    (fMat3->data[1] - sMat3->data[1]),
    (fMat3->data[2] - sMat3->data[2]),
    (fMat3->data[3] - sMat3->data[3]),
    (fMat3->data[4] - sMat3->data[4]),
    (fMat3->data[5] - sMat3->data[5]),
    (fMat3->data[6] - sMat3->data[6]),
    (fMat3->data[7] - sMat3->data[7]),
    (fMat3->data[8] - sMat3->data[8]));
}

Mat3* mat3_mult(Mat3* fMat3, Mat3* sMat3)
{
    mat_t data[9];

    data[0] = fMat3->data[0] * sMat3->data[0] + fMat3->data[1] * sMat3->data[3] + fMat3->data[2] * sMat3->data[6];
    data[1] = fMat3->data[0] * sMat3->data[1] + fMat3->data[1] * sMat3->data[4] + fMat3->data[2] * sMat3->data[7];
    data[2] = fMat3->data[0] * sMat3->data[2] + fMat3->data[1] * sMat3->data[5] + fMat3->data[2] * sMat3->data[8];
    data[4] = fMat3->data[3] * sMat3->data[0] + fMat3->data[4] * sMat3->data[3] + fMat3->data[5] * sMat3->data[6];
    data[5] = fMat3->data[3] * sMat3->data[1] + fMat3->data[4] * sMat3->data[4] + fMat3->data[5] * sMat3->data[7];
    data[6] = fMat3->data[3] * sMat3->data[2] + fMat3->data[4] * sMat3->data[5] + fMat3->data[5] * sMat3->data[8];
    data[7] = fMat3->data[6] * sMat3->data[0] + fMat3->data[7] * sMat3->data[3] + fMat3->data[8] * sMat3->data[6];
    data[7] = fMat3->data[6] * sMat3->data[1] + fMat3->data[7] * sMat3->data[4] + fMat3->data[8] * sMat3->data[7];
    data[7] = fMat3->data[6] * sMat3->data[2] + fMat3->data[7] * sMat3->data[5] + fMat3->data[8] * sMat3->data[8];
                 
    return mat3_new_array(data);
}

Mat3* mat3_scale(Mat3* mat3, mat_t scale)
{
    return mat3_new(
    (mat3->data[0] * scale),
    (mat3->data[1] * scale),
    (mat3->data[2] * scale),
    (mat3->data[3] * scale),
    (mat3->data[4] * scale),
    (mat3->data[5] * scale),
    (mat3->data[6] * scale),
    (mat3->data[7] * scale),
    (mat3->data[8] * scale));
}

mat_t mat3_trace(Mat3* mat3)
{
    return mat3->data[0] + mat3->data[4] + mat3->data[8];
}

mat_t mat3_sum(Mat3* mat3)
{
    return 
    mat3->data[0] + mat3->data[1] + mat3->data[2] + 
    mat3->data[3] + mat3->data[4] + mat3->data[5] + 
    mat3->data[6] + mat3->data[7] + mat3->data[8];
}

mat_t mat3_determinant(Mat3* mat3)
{
    mat_t first = 
    mat3->data[0] * (mat3->data[4] * mat3->data[8] - mat3->data[5] * mat3->data[7]);

    mat_t second = 
    mat3->data[1] * (mat3->data[3] * mat3->data[8] - mat3->data[5] * mat3->data[6]);

    mat_t third = 
    mat3->data[2] * (mat3->data[3] * mat3->data[7] - mat3->data[4] * mat3->data[6]);

    return first - second + third;
}

Mat3* mat3_inverse(Mat3* mat3)
{
    mat_t scale = 1.00000f / mat3_determinant(mat3);
    return mat3_scale(mat3,scale);
}

Mat3* mat3_negative(Mat3* mat3)
{
    return mat3_new(
    (mat3->data[0] * -1),
    (mat3->data[1] * -1),
    (mat3->data[2] * -1),
    (mat3->data[3] * -1),
    (mat3->data[4] * -1),
    (mat3->data[5] * -1),
    (mat3->data[6] * -1),
    (mat3->data[7] * -1),
    (mat3->data[8] * -1));
}

Mat3* mat3_transpose(Mat3* mat3)
{
    return mat3_new(
    mat3->data[0],
    mat3->data[3],
    mat3->data[6],
    mat3->data[1],
    mat3->data[4],
    mat3->data[7],
    mat3->data[2],
    mat3->data[5],
    mat3->data[8]);
}

int mat3_equal(Mat3* fMat3, Mat3* sMat3)
{
    int equals = 
    fMat3->data[0] == sMat3->data[0] &&
    fMat3->data[1] == sMat3->data[1] &&
    fMat3->data[2] == sMat3->data[2] &&
    fMat3->data[3] == sMat3->data[3] &&
    fMat3->data[4] == sMat3->data[4] &&
    fMat3->data[5] == sMat3->data[5] &&
    fMat3->data[6] == sMat3->data[6] &&
    fMat3->data[7] == sMat3->data[7] &&
    fMat3->data[8] == sMat3->data[8]; 
    return equals;
}

int mat3_not_equal(Mat3* fMat3, Mat3* sMat3)
{
    return !mat3_equal(fMat3, sMat3);
}

int mat3_greater(Mat3* fMat3, Mat3* sMat3)
{
    int equals = 
    fMat3->data[0] > sMat3->data[0] &&
    fMat3->data[1] > sMat3->data[1] &&
    fMat3->data[2] > sMat3->data[2] &&
    fMat3->data[3] > sMat3->data[3] &&
    fMat3->data[4] > sMat3->data[4] &&
    fMat3->data[5] > sMat3->data[5] &&
    fMat3->data[6] > sMat3->data[6] &&
    fMat3->data[7] > sMat3->data[7] &&
    fMat3->data[8] > sMat3->data[8]; 
    return equals;
}

int mat3_less(Mat3* fMat3, Mat3* sMat3)
{
    return mat3_greater(sMat3, fMat3);
}

int mat3_greater_equal(Mat3* fMat3, Mat3* sMat3)
{
    return !mat3_less(fMat3, sMat3);
}

int mat3_less_equal(Mat3* fMat3, Mat3* sMat3)
{
    return !mat3_greater(fMat3, sMat3);
}

#else

Mat3 mat3_new_null()
{
    Mat3* newMat3 = malloc(sizeof(Mat3));
    return *newMat3;
}

Mat3 mat3_new(mat_t m11, mat_t m12, mat_t m13,
               mat_t m21, mat_t m22, mat_t m23,
               mat_t m31, mat_t m32, mat_t m33)
{
    Mat3* newMat3 = malloc(sizeof(Mat3));
    newMat3->data[0] = m11;
    newMat3->data[1] = m12;
    newMat3->data[2] = m13;
    newMat3->data[3] = m21;
    newMat3->data[4] = m22;
    newMat3->data[5] = m23;
    newMat3->data[6] = m31;
    newMat3->data[7] = m32;
    newMat3->data[8] = m33;
    return *newMat3;
}

Mat3 mat3_new_array(mat_t* data)
{
    return mat3_new(
    data[0],data[1],data[2],
    data[3],data[4],data[5],
    data[6],data[7],data[8]);
}

Mat3 mat3_copy(Mat3 mat3)
{
    return mat3_new_array(mat3.data);
}

void mat3_print(Mat3 mat3)
{
#ifdef _CMATH_MAT_LDOUBLE
    printf("[ %Lf %Lf %Lf ]\n",mat3.data[0], mat3.data[1], mat3.data[2]);
    printf("[ %Lf %Lf %Lf ]\n",mat3.data[3], mat3.data[4], mat3.data[5]);
    printf("[ %Lf %Lf %Lf ]\n",mat3.data[6], mat3.data[7], mat3.data[8]);
#else
    printf("[ %f %f %f ]\n",mat3.data[0], mat3.data[1], mat3.data[2]);
    printf("[ %f %f %f ]\n",mat3.data[3], mat3.data[4], mat3.data[5]);
    printf("[ %f %f %f ]\n",mat3.data[6], mat3.data[7], mat3.data[8]);
#endif
}

Mat3 mat3_add(Mat3 fMat3, Mat3 sMat3)
{
    return mat3_new(
    (fMat3.data[0] + sMat3.data[0]),
    (fMat3.data[1] + sMat3.data[1]),
    (fMat3.data[2] + sMat3.data[2]),
    (fMat3.data[3] + sMat3.data[3]),
    (fMat3.data[4] + sMat3.data[4]),
    (fMat3.data[5] + sMat3.data[5]),
    (fMat3.data[6] + sMat3.data[6]),
    (fMat3.data[7] + sMat3.data[7]),
    (fMat3.data[8] + sMat3.data[8]));
}

Mat3 mat3_sub(Mat3 fMat3, Mat3 sMat3)
{
    return mat3_new(
    (fMat3.data[0] - sMat3.data[0]),
    (fMat3.data[1] - sMat3.data[1]),
    (fMat3.data[2] - sMat3.data[2]),
    (fMat3.data[3] - sMat3.data[3]),
    (fMat3.data[4] - sMat3.data[4]),
    (fMat3.data[5] - sMat3.data[5]),
    (fMat3.data[6] - sMat3.data[6]),
    (fMat3.data[7] - sMat3.data[7]),
    (fMat3.data[8] - sMat3.data[8]));
}

Mat3 mat3_mult(Mat3 fMat3, Mat3 sMat3)
{
    mat_t data[9];

    data[0] = fMat3.data[0] * sMat3.data[0] + fMat3.data[1] * sMat3.data[3] + fMat3.data[2] * sMat3.data[6];
    data[1] = fMat3.data[0] * sMat3.data[1] + fMat3.data[1] * sMat3.data[4] + fMat3.data[2] * sMat3.data[7];
    data[2] = fMat3.data[0] * sMat3.data[2] + fMat3.data[1] * sMat3.data[5] + fMat3.data[2] * sMat3.data[8];
    data[4] = fMat3.data[3] * sMat3.data[0] + fMat3.data[4] * sMat3.data[3] + fMat3.data[5] * sMat3.data[6];
    data[5] = fMat3.data[3] * sMat3.data[1] + fMat3.data[4] * sMat3.data[4] + fMat3.data[5] * sMat3.data[7];
    data[6] = fMat3.data[3] * sMat3.data[2] + fMat3.data[4] * sMat3.data[5] + fMat3.data[5] * sMat3.data[8];
    data[7] = fMat3.data[6] * sMat3.data[0] + fMat3.data[7] * sMat3.data[3] + fMat3.data[8] * sMat3.data[6];
    data[7] = fMat3.data[6] * sMat3.data[1] + fMat3.data[7] * sMat3.data[4] + fMat3.data[8] * sMat3.data[7];
    data[7] = fMat3.data[6] * sMat3.data[2] + fMat3.data[7] * sMat3.data[5] + fMat3.data[8] * sMat3.data[8];
                 
    return mat3_new_array(data);
}

Mat3 mat3_scale(Mat3 mat3, mat_t scale)
{
    return mat3_new(
    (mat3.data[0] * scale),
    (mat3.data[1] * scale),
    (mat3.data[2] * scale),
    (mat3.data[3] * scale),
    (mat3.data[4] * scale),
    (mat3.data[5] * scale),
    (mat3.data[6] * scale),
    (mat3.data[7] * scale),
    (mat3.data[8] * scale));
}

mat_t mat3_trace(Mat3 mat3)
{
    return mat3.data[0] + mat3.data[4] + mat3.data[8];
}

mat_t mat3_sum(Mat3 mat3)
{
    return 
    mat3.data[0] + mat3.data[1] + mat3.data[2] + 
    mat3.data[3] + mat3.data[4] + mat3.data[5] + 
    mat3.data[6] + mat3.data[7] + mat3.data[8];
}

mat_t mat3_determinant(Mat3 mat3)
{
    mat_t first = 
    mat3.data[0] * (mat3.data[4] * mat3.data[8] - mat3.data[5] * mat3.data[7]);

    mat_t second = 
    mat3.data[1] * (mat3.data[3] * mat3.data[8] - mat3.data[5] * mat3.data[6]);

    mat_t third = 
    mat3.data[2] * (mat3.data[3] * mat3.data[7] - mat3.data[4] * mat3.data[6]);
    return first - second + third;
}

Mat3 mat3_inverse(Mat3 mat3)
{
    mat_t scale = 1.00000f / mat3_determinant(mat3);
    return mat3_scale(mat3,scale);
}

Mat3 mat3_negative(Mat3 mat3)
{
    return mat3_new(
    (mat3.data[0] * -1),
    (mat3.data[1] * -1),
    (mat3.data[2] * -1),
    (mat3.data[3] * -1),
    (mat3.data[4] * -1),
    (mat3.data[5] * -1),
    (mat3.data[6] * -1),
    (mat3.data[7] * -1),
    (mat3.data[8] * -1));
}

Mat3 mat3_transpose(Mat3 mat3)
{
    return mat3_new(
    mat3.data[0],
    mat3.data[3],
    mat3.data[6],
    mat3.data[1],
    mat3.data[4],
    mat3.data[7],
    mat3.data[2],
    mat3.data[5],
    mat3.data[8]);
}

int mat3_equal(Mat3 fMat3, Mat3 sMat3)
{
    int equals = 
    fMat3.data[0] == sMat3.data[0] &&
    fMat3.data[1] == sMat3.data[1] &&
    fMat3.data[2] == sMat3.data[2] &&
    fMat3.data[3] == sMat3.data[3] &&
    fMat3.data[4] == sMat3.data[4] &&
    fMat3.data[5] == sMat3.data[5] &&
    fMat3.data[6] == sMat3.data[6] &&
    fMat3.data[7] == sMat3.data[7] &&
    fMat3.data[8] == sMat3.data[8]; 
    return equals;
}

int mat3_not_equal(Mat3 fMat3, Mat3 sMat3)
{
    return !mat3_equal(fMat3, sMat3);
}

int mat3_greater(Mat3 fMat3, Mat3 sMat3)
{
    int equals = 
    fMat3.data[0] > sMat3.data[0] &&
    fMat3.data[1] > sMat3.data[1] &&
    fMat3.data[2] > sMat3.data[2] &&
    fMat3.data[3] > sMat3.data[3] &&
    fMat3.data[4] > sMat3.data[4] &&
    fMat3.data[5] > sMat3.data[5] &&
    fMat3.data[6] > sMat3.data[6] &&
    fMat3.data[7] > sMat3.data[7] &&
    fMat3.data[8] > sMat3.data[8]; 
    return equals;
}

int mat3_less(Mat3 fMat3, Mat3 sMat3)
{
    return mat3_greater(sMat3, fMat3);
}

int mat3_greater_equal(Mat3 fMat3, Mat3 sMat3)
{
    return !mat3_less(fMat3, sMat3);
}

int mat3_less_equal(Mat3 fMat3, Mat3 sMat3)
{
    return !mat3_greater(fMat3, sMat3);
}

#endif

void mat3_assign(Mat3* dest, const Mat3* src)
{
    dest->data[0] = src->data[0];
    dest->data[1] = src->data[1];
    dest->data[2] = src->data[2];
    dest->data[3] = src->data[3];
    dest->data[4] = src->data[3];
    dest->data[5] = src->data[5];
    dest->data[6] = src->data[6];
    dest->data[7] = src->data[7];
    dest->data[8] = src->data[8];
}