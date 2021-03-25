/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_math.c' is apart of the 'clib-linear-algebra' library, 
and contains mathematical function definitions such as tranpose, add, 
inverse, determinant, and more for matrices.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

The GitHub repository for this library can be found here:
https://github.com/James-Durban/linear-algebra_library
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "matrix_math.h"
#include "lalgebra_errors.h"

Matrix* matrix_add(Matrix* fMat, Matrix* sMat)
{
    int equals = ((fMat->cols * fMat->rows != sMat->cols * sMat->rows));
    ASSERT(equals,"Rows and columns are not equal!");
    double* cnt = malloc(sizeof(cnt) * (fMat->rows * fMat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int index = 0;
    for(int i = 0; i < fMat->rows; i++)
    {
        for(int j = 0; j < fMat->cols; j++)
        {
            if(fMat->order == COLUMN_MAJOR) { index = i + (j * fMat->rows); }
            else { index = j + (i * fMat->rows); }
            cnt[index] = fMat->data[index] + sMat->data[index];
        }
    }
    return matrix_new(fMat->rows,fMat->cols,fMat->order,cnt);
}

Matrix* matrix_sub(Matrix* fMat, Matrix* sMat)
{
    int equals = ((fMat->cols * fMat->rows != sMat->cols * sMat->rows));
    ASSERT(equals,"Rows and columns are not equal!");
    double* cnt = malloc(sizeof(cnt) * (fMat->rows * fMat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int index = 0;
    for(int i = 0; i < fMat->rows; i++)
    {
        for(int j = 0; j < fMat->cols; j++)
        {
            if(fMat->order == COLUMN_MAJOR) { index = i + (j * fMat->rows); }
            else { index = j + (i * fMat->rows); }
            cnt[index] = fMat->data[index] - sMat->data[index];
        }
    }
    return matrix_new(fMat->rows,fMat->cols,fMat->order,cnt);
}

Matrix* matrix_mult(Matrix* fMat, Matrix* sMat, enum MatrixOrder order)
{
    int equals = ((fMat->cols * fMat->rows != sMat->cols * sMat->rows));
    ASSERT(equals,"Rows and columns are not equal!");
    double* cnt = malloc(sizeof(cnt) * (fMat->rows * fMat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    double sum = 0.0;
    int indexFirst, indexSecond;
    for(int i = 0; i < fMat->rows; i++)
    {
        for(int j = 0; j < fMat->cols; j++)
        {
            sum = 0.0f;
            for(int k = 0; k < fMat->rows; k++)
            {
                if(order == COLUMN_MAJOR)
                {
                    indexFirst = j + (k * fMat->rows);
                    indexSecond = k + (i * fMat->rows);
                }
                else
                {
                    indexFirst = k + (i * fMat->rows);
                    indexSecond = j + (k * fMat->rows);
                }
                sum += fMat->data[indexFirst] * sMat->data[indexSecond];

            }
            cnt[j + i * fMat->rows] = sum;
        }

    }
    return matrix_new(fMat->rows,fMat->cols,fMat->order,cnt);
}

Matrix* matrix_mult_scale(Matrix* mat, double scale)
{
    double* cnt = malloc(sizeof(cnt) * (mat->rows * mat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        for(int j = 0; j < mat->cols; j++)
        {
            if(mat->order == COLUMN_MAJOR)
            {   
                index = i + (j * mat->rows);
            }
            else
            {
                index = j + (i * mat->rows);
            }
            cnt[index] = mat->data[index] * scale;
        }
    }
    return matrix_new(mat->rows,mat->cols,mat->order,cnt);
}

Matrix* matrix_inverse(Matrix* mat)
{
    ASSERT(mat->cols != mat->rows, "Rows does not equal columns!");
    Matrix* identityMatrix = matrix_new_identity(mat->rows);
    double* row = malloc(sizeof(row) * (mat->rows * mat->cols));
    ASSERT(row == NULL,"Failed to allocate memory for new data!");

    int indexFirst,indexSecond = 0;
    for(int j = 0; j < mat->rows; j++)
    {
        indexFirst = j + (0 * mat->rows);
        indexSecond = j + (1 * mat->rows);

        row[indexFirst] += mat->data[indexSecond];
        row[indexFirst] /= 5;
        row[indexSecond] -= (2 * row[indexFirst]);
        row[indexSecond] *= (-1/2);

        identityMatrix->data[indexFirst] += identityMatrix->data[indexSecond];
        identityMatrix->data[indexFirst] /= 5;
        identityMatrix->data[indexSecond] -= (2 * identityMatrix->data[indexFirst]);
        identityMatrix->data[indexSecond] *= (-1/2);
    }
    return identityMatrix;
}

Matrix* matrix_negative(Matrix* mat)
{
    double* cnt = malloc(sizeof(cnt) * (mat->rows * mat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        for(int j = 0; j < mat->cols; j++)
        {
            if(mat->order == COLUMN_MAJOR)
            {   
                index = i + (j * mat->rows);
            }
            else
            {
                index = j + (i * mat->rows);
            }
            cnt[index] = mat->data[index] * -1;
        }
    }
    return matrix_new(mat->rows,mat->cols,mat->order,cnt);
}

Matrix* matrix_transpose(Matrix* mat)
{
    double* cnt = malloc(sizeof(cnt) * (mat->rows * mat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int indexFirst,indexSecond = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        for(int j = 0; j < mat->cols; j++)
        {
            if(mat->order == COLUMN_MAJOR)
            {   
                indexFirst = i + (j * mat->rows);
                indexSecond = j + (i * mat->rows);
            }
            else
            {
                indexFirst = j + (i * mat->rows);
                indexSecond = i + (j * mat->rows);
            }
            cnt[indexSecond] = mat->data[indexFirst];
        }
    }
    return matrix_new(mat->rows,mat->cols,mat->order,cnt);
}

Matrix* matrix_rotate_clockwise(Matrix* mat, int angle)
{

    //validation
    ASSERT((angle % 90 != 0), "Angle must be in multiples of 90 degrees.");

    double* cnt = malloc(sizeof(cnt) * (mat->rows * mat->cols));
    ASSERT(cnt == NULL,"Failed to allocate memory for new data!");

    int index = 0;
    int cntIndex = 0;
    
    //This currently rotates the matrix by 90 degrees.
    //I will need to understand a pattern for other degrees, rather than writing 3 implementations
    //for 90,180, and 270 rotations. 
    //we need to copy each column.

    for(int i = 0; i < mat->cols; i++)
    {
        for(int j = mat->cols-1; j > -1; j--)
        {
            index = i + (j * mat->rows);

            cnt[cntIndex] = mat->data[index];
            cntIndex++;
        }
    }


    return matrix_new(mat->rows,mat->cols,ROW_MAJOR,cnt);
}