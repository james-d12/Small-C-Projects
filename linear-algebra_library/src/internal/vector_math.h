/*************************************************************************
Copyright 2019 James Durban

The file 'vector_math.h' is apart of the 'clib-linear-algebra' library, 
and contains a variety of mathematical function prototypes such as 
adding, subtracting, magntiude, normalising, and more on vectors.

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

#ifndef _VECTOR_MATH_H
#define _VECTOR_MATH_H

#include "vector_object.h"


//possibly remove these functions, after the variadic functions are implemented.

Vector* vector_add(Vector* fVec, Vector* sVec);
Vector* vector_sub(Vector* fVec, Vector* sVec);
Vector* vector_mult(Vector* fVec, Vector* sVec);
Vector* vector_mult_scale(Vector* vec, double scale);
Vector* vector_div(Vector* fVec, Vector* sVec);

//add variadic functions - can perform vector operations on any number of vectors 
//The dimensions of the vectors must be the same. 
//could use either pointers, or ... argument.

Vector* vector_add_many(int count, Vector* vecList);
Vector* vector_sub_many(int count, Vector* vecList);
Vector* vector_mult_many(int count, Vector* vecList);
Vector* vector_div_many(int count, Vector* vecList);

double  vector_magnitude(Vector* vec);
Vector* vector_normalise(Vector* vec);

double  vector_dot(Vector* fVec, Vector* sVec);

double  vector_dot_many(int count, Vector* vecList);

double  vector_dot_angle(Vector* fVec, Vector* sVec, double angle);
Vector* vector_cross(Vector* fVec, Vector* sVec);
Vector* vector_cross_angle(Vector* fVec, Vector* sVec, double angle);
double  vector_scalar_triplet_product(Vector* fVec, Vector* sVec, Vector* tVec);

//implement a generic scalar product function for varying number of vectors.

double  vector_dir_cos_a(Vector* vec);
double  vector_dir_cos_b(Vector* vec);
double  vector_angle_between_vector(Vector* fVec, Vector* sVec);

double  vector_projection(Vector* fVec, Vector* sVec);

#endif