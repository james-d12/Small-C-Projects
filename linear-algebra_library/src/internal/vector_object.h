/*************************************************************************
Copyright 2019 James Durban

The file 'vector_object.h' is apart of the 'clib-linear-algebra' library, 
and contains a variety of memory related function prototypes for creating, 
copying, and destroying vectors.

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

#ifndef _VECTOR_OBJECT_H
#define _VECTOR_OBJECT_H

typedef struct Vector
{
    int size;
    double* data;
}Vector;

extern Vector internal_vec2_unit;
extern Vector internal_vec3_unit;
extern Vector internal_vec4_unit;

#define VECTOR2_UNIT &internal_vec2_unit
#define VECTOR3_UNIT &internal_vec3_unit
#define VECTOR4_UNIT &internal_vec4_unit

/* Creation, Copy and Deletion - Memory Management */

Vector* vector_new(int size);
Vector* vector_new_null(int size);
Vector* vector_new_array(int size, double* data);

Vector* vector_copy(const Vector* vec);

void    vector_delete(Vector** vec);
void    vector_print(const Vector* vec);
#endif