/*************************************************************************
Copyright 2019 James Durban

The file 'vector_comp.h' is apart of the 'clib-linear-algebra' library, 
and contains a variety of comparison function prototypes such as equals, 
collinear, less than, and more for vectors.

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

#ifndef _VECTOR_COMP_H
#define _VECTOR_COMP_H

#include "vector_object.h"

int vector_equal(Vector* fVec, Vector* sVec); 
int vector_not_equal(Vector* fVec, Vector* sVec);
int vector_less(Vector* fVec, Vector* sVec);
int vector_greater(Vector* fVec, Vector* sVec);
int vector_less_equal(Vector* fVec, Vector* sVec);
int vector_greater_equal(Vector* fVec, Vector* sVec);

int vector_is_collinear(Vector* fVec, Vector* sVec);
int vector_is_orthogonal(Vector* fVec, Vector* sVec);
int vector_is_coplanar(Vector* fVec, Vector* sVec, Vector* tVec);

#endif