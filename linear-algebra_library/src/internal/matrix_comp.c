/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_comp.c' is apart of the 'clib-linear-algebra' library, 
and contains comparison function definitions such equal, not equal, 
is row, is column, and more for matrices.

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

#include "matrix_comp.h"

#include <stdio.h>
#include "matrix_math.h"
#include "lalgebra_errors.h"

int matrix_is_equal(Matrix* fMat, Matrix* sMat)
{
    if((fMat->rows * sMat->cols) != (sMat->rows * fMat->cols)) { return 0; }

    int isEqual = 1;
    int index = 0;
    for(int i = 0; i < fMat->rows; i++)
    {
        for(int j = 0; j < fMat->cols; j++)
        {
            switch (fMat->order)
            {
                case COLUMN_MAJOR: index = i + (j * fMat->rows); break;
                case ROW_MAJOR: index = j + (i * sMat->rows); break;
            }
            if(fMat->data[index] != sMat->data[index]) { isEqual = 0; }
        }
    }
    return isEqual;
}

int matrix_is_not_equal(Matrix* fMat, Matrix* sMat) 
{
    return !matrix_is_equal(fMat,sMat);
}

int matrix_is_less(Matrix* fMat, Matrix* sMat)
{
    if((fMat->rows * sMat->cols) != (sMat->rows * fMat->cols)) { return 0; }

    int isEqual = 1;
    int index = 0;
    for(int i = 0; i < fMat->rows; i++)
    {
        for(int j = 0; j < fMat->cols; j++)
        {
            switch (fMat->order)
            {
                case COLUMN_MAJOR: index = i + (j * fMat->rows); break;
                case ROW_MAJOR: index = j + (i * sMat->rows); break;
            }
            if(fMat->data[index] >= sMat->data[index]) { isEqual = 0; }
        }
    }
    return isEqual;
}

int matrix_is_greater(Matrix* fMat, Matrix* sMat)
{
    return matrix_is_less(sMat,fMat);
}

int matrix_is_less_equal(Matrix* fMat, Matrix* sMat)
{
    return !matrix_is_greater(fMat,sMat);
}

int matrix_is_greater_equal(Matrix* fMat, Matrix* sMat)
{
    return !matrix_is_greater(fMat,sMat);
}

int matrix_is_row(Matrix* mat) { return (mat->rows == 1 && mat->cols >= 2) ? 1 : 0; }

int matrix_is_column(Matrix* mat) { return (mat->cols == 1 && mat->rows >= 2) ? 1 : 0;}

int matrix_is_rectangular(Matrix* mat) { return (mat->cols != mat->rows) ? 1 : 0; }

int matrix_is_square(Matrix*mat) { return (mat->cols == mat->rows) ? 1 : 0; }

int matrix_is_identity(Matrix* mat)
{
    if(!matrix_is_square(mat)) { return 0; }

    return matrix_is_equal(mat,matrix_new_identity(mat->rows));
}

int matrix_is_diagonal(Matrix* mat)
{
    if(!matrix_is_square(mat)) { return 0; }

    int res = 1;
    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        if(mat->data[index] != 0.0) { res = 0; }
        index += (mat->rows + 1);
    }
    return res;
}

int matrix_is_scalar(Matrix* mat)
{
    if(!matrix_is_square(mat)) { return 0; }
    
    int res = 1;
    int index = 0;
    int diagIndex = 0;

    for(int i = 0; i < mat->rows; i++)
    {
        if(mat->data[index] == 0.0) { res = 0; }
        diagIndex += (mat->rows + 1);
        for(int j = 0; j < mat->cols; j++)
        {
            if(mat->order == COLUMN_MAJOR) { index = i + (j * mat->rows); }
            else { index = j + (i * mat->rows); }
            
            if(mat->data[index] != 0.0) { res = 0; }
        }
    }
    return res;
}

int matrix_is_triangular_upper(Matrix* mat)
{
    if(!matrix_is_square(mat)) { return 0; }

    int res = 1;
    int offset = 1;
    int col = 1;

    for(int j = 1; j < mat->rows; j++)
    { 
        for(int i = col; i < mat->rows; i++)
        {
            if(mat->data[offset] != 0.0) { res = 0; }
            printf("val: %f\n offset: %d\n",mat->data[offset],offset);
            offset++;
        }
        offset = (col * mat->rows + (j + 1));
        col++;
    }
    return res;
}

int matrix_is_triangular_lower(Matrix* mat)
{
    if(!matrix_is_square(mat)) { return 0; }

    int res = 1;
    int offset = mat->rows;
    int col = 1;

    for(int j = 1; j < mat->rows; j++)
    { 
        for(int i = col; i < mat->rows; i++)
        {
            if(mat->data[offset] != 0.0f) { res = 0; }
            printf("%f\n",mat->data[offset]);
            offset += (mat->rows + 1);
        }
        col++;
        offset = (col * mat->rows);
    }
    return res;
}

int matrix_is_symmetric(Matrix* mat)
{
    return matrix_is_equal(mat,matrix_transpose(mat));
}
