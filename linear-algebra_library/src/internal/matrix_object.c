/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_object.c' is apart of the 'clib-linear-algebra' library, 
and contains memory management function definitions for matrices such as
copy, new, delete and even some IO operations.

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

#include "matrix_object.h"
#include "lalgebra_errors.h"

Matrix* internal_mat_create(int rows, int cols, MatrixOrder order)
{
    ASSERT((rows < 0 || cols < 0),"Given dimensions are invalid!");
    Matrix* newMat = malloc(sizeof(*newMat));
    ASSERT((newMat == NULL),"Failed to allocate memory for matrix!");
    newMat->data = malloc(sizeof(*newMat->data) * (rows * cols));
    ASSERT((newMat->data == NULL),"Failed to allocate memory for matrix data!");
    newMat->rows = rows;
    newMat->cols = cols;
    newMat->order = order;
    return newMat;
}

Matrix* matrix_new(int rows, int cols, MatrixOrder order, double* data)
{
    Matrix* newMat = internal_mat_create(rows,cols,order); 
    int index = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            switch (order)
            {
                case COLUMN_MAJOR: index = i + (j * rows); break;
                case ROW_MAJOR: index = j + (i * rows); break;
            }
            newMat->data[index] = data[index];
        }
    }
    return newMat;
}

Matrix* matrix_new_null(int rows, int cols, MatrixOrder order)
{
    Matrix* newMat = internal_mat_create(rows,cols,order);
    int index = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            switch (order)
            {
                case COLUMN_MAJOR: index = i + (j * rows); break;
                case ROW_MAJOR: index = j + (i * rows); break;
            }
            newMat->data[index] = 0.0;
        }
    }
    return newMat;
}

Matrix* matrix_new_identity(int dimensions)
{
    Matrix* newMat = internal_mat_create(dimensions,dimensions,ROW_MAJOR);
    int index = 0;
    for(int i = 0; i < dimensions; i++)
    {
        newMat->data[index] = 1.0;
        index += (dimensions + 1);
    } 
    return newMat;
}

void matrix_resize(Matrix* mat, int newRow, int newCol)
{
    ASSERT((newRow < 0 || newCol < 0),"Given dimensions are invalid!");
    mat->rows = newRow;
    mat->cols = newCol;
    mat->data = realloc(mat->data, sizeof(double) * (newRow * newCol));
    ASSERT((mat->data == NULL),"Failed to allocate memory for matrix data!");
}

Matrix* matrix_copy(Matrix* mat)
{
    double* newData = malloc(sizeof(*newData) * (mat->rows * mat->cols));
    ASSERT((newData == NULL),"Failed to allocate memory for new data!");
    
    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        for(int j = 0; j < mat->cols; j++)
        {
            switch (mat->order)
            {
                case COLUMN_MAJOR: index = i + (j * mat->rows); break;
                case ROW_MAJOR: index = j + (i * mat->rows); break;
            }
            newData[index] = mat->data[index];
        }
    }
    return matrix_new(mat->rows,mat->cols,mat->order,newData);
}

Matrix* matrix_copy_row(Matrix* mat, int row)
{
    double* newData = malloc(sizeof(*newData) * (1 * mat->cols));
    ASSERT((newData == NULL),"Failed to allocate memory for new data!");

    int index = 0;
    for(int j = 0; j < mat->cols; j++)
    {
        index = j + (row * mat->rows);
        newData[index] = mat->data[index];
    }
    return matrix_new(1,mat->cols,COLUMN_MAJOR,newData);
}

Matrix* matrix_copy_column(Matrix* mat, int col)
{
    double* newData = malloc(sizeof(newData) * (mat->rows * 1));
    ASSERT((newData == NULL),"Failed to allocate memory for new data!");

    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        index = i + (col * mat->rows);
        newData[index] = mat->data[index];
    }
    return matrix_new(mat->rows,1,COLUMN_MAJOR,newData);
}

//change this, it will free the pointer, not the actual data.
void matrix_delete(Matrix** mat)
{

    free((*mat)->data);
    free((*mat));
    *mat = NULL;
}

void matrix_print(Matrix* mat)
{
    int index = 0;
    for(int i = 0; i < mat->rows; i++)
    {
        printf("[ ");
        for(int j = 0; j < mat->cols; j++)
        {
            switch (mat->order)
            {
                case COLUMN_MAJOR: index = i + (j * mat->rows); break;
                case ROW_MAJOR: index = j + (i * mat->rows); break;
            }
            printf("%f ",mat->data[index]);
        }
        printf("]\n");
    }
}
