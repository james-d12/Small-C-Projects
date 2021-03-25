/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_object.h' is apart of the 'clib-linear-algebra' library, 
and contains memory management function prototypes for matrices such as
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

#ifndef _MATRIX_OBJECT_H
#define _MATRIX_OBJECT_H

#include "order.h"

typedef struct Matrix
{
    int rows;
    int cols;
    MatrixOrder order;
    double* data;
}Matrix;

/* Matrix allocation operations */

Matrix* matrix_new(int rows, int cols, MatrixOrder order, double* data);
Matrix* matrix_new_null(int rows, int cols, MatrixOrder order);
Matrix* matrix_new_identity(int dimensions);

void    matrix_resize(Matrix* mat, int newRows, int newCol);

Matrix* matrix_copy(Matrix* mat);
Matrix* matrix_copy_row(Matrix* mat, int row);
Matrix* matrix_copy_column(Matrix* mat, int col);

void    matrix_delete(Matrix** mat);
void    matrix_print(Matrix* mat);

#endif