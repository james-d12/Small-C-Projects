/*************************************************************************
Copyright 2019 James Durban

The file 'matrix_math.h' is apart of the 'clib-linear-algebra' library, 
and contains mathematical function prototypes such as tranpose, add, 
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

#ifndef _MATRIX_MATH_H
#define _MATRIX_MATH_H

#include "matrix_object.h"

Matrix* matrix_add(Matrix* fMat, Matrix* sMat);
Matrix* matrix_sub(Matrix* fMat, Matrix* sMat);
Matrix* matrix_mult(Matrix* fMat, Matrix* sMat, MatrixOrder order);
Matrix* matrix_mult_scale(Matrix* mat, double scale);

//implement varadic functions for matrix calculations.

Matrix* matrix_determinant(Matrix* mat);
Matrix* matrix_inverse(Matrix* mat);
Matrix* matrix_negative(Matrix* mat);
Matrix* matrix_transpose(Matrix* mat);

Matrix* matrix_rotate_clockwise(Matrix* mat, int angle);
Matrix* matrix_rotate_anticlockwise(Matrix* mat, int angle);

#endif
