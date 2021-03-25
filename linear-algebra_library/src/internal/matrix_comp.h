/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_comp.h' is apart of the 'clib-linear-algebra' library, 
and contains comparison function prototypes such equal, not equal, 
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

#ifndef _MATRIX_COMP_H
#define _MATRIX_COMP_H

#include "matrix_object.h"

int matrix_is_not_equal(Matrix* fMat, Matrix* sMat);
int matrix_is_less(Matrix* fMat, Matrix* sMat);
int matrix_is_equal(Matrix* fMat, Matrix* sMat);
int matrix_is_greater(Matrix* fMat, Matrix* sMat);
int matrix_is_less_equal(Matrix* fMat, Matrix* sMat);
int matrix_is_greater_equal(Matrix* fMat, Matrix* sMat);

int matrix_is_row(Matrix* mat);
int matrix_is_column(Matrix* mat);
int matrix_is_square(Matrix* mat);
int matrix_is_rectangular(Matrix* mat);
int matrix_is_identity(Matrix* mat);
int matrix_is_diagonal(Matrix* mat);
int matrix_is_scalar(Matrix* mat);
int matrix_is_null(Matrix* mat);
int matrix_is_triangular_upper(Matrix* mat);
int matrix_is_triangular_lower(Matrix* mat);
int matrix_is_symmetric(Matrix* mat);

#endif