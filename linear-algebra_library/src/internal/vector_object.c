/*************************************************************************
Copyright 2019 James Durban

The file 'vector_object.c' is apart of the 'clib-linear-algebra' library, 
and contains a variety of memory related function definitions for creating, 
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

#include <stdio.h>
#include <stdlib.h>

#include "vector_object.h"
#include "lalgebra_errors.h"

Vector internal_vec2_unit = {2,(double[]){1,1}};
Vector internal_vec3_unit = {3,(double[]){1,1,1}};
Vector internal_vec4_unit = {4,(double[]){1,1,1,1}};

Vector* vector_new(int size)
{
    Vector* newVec = malloc(sizeof(newVec));
    ASSERT((newVec == NULL),"Failed to allocate memory for vector!");
    newVec->data = malloc(sizeof(newVec->data) * size);
    ASSERT((newVec->data == NULL),"Failed to allocate memory for vector data!");
    newVec->size = size;
    return newVec;
}

Vector* vector_new_null(int size)
{
    Vector* newVec = vector_new(size);
    for(int i = 0; i < size; i++)
    {
        newVec->data[i] = 0.0;
    }
    return newVec;
}

Vector* vector_new_array(int size, double* data)
{
    Vector* newVec = vector_new(size);
    for(int i = 0; i < size; i++)
    {
        newVec->data[i] = data[i];
    }
    return newVec;
}

Vector* vector_copy(const Vector* vec)
{
    Vector* newVec = vector_new(vec->size);
    for(int i = 0; i < vec->size; i++)
    {
        newVec->data[i] = vec->data[i];
    }
    return newVec;
}

void vector_delete(Vector** vec)
{
    free((*vec)->data);
    free((*vec));
    *vec = NULL;
}

void vector_print(const Vector* vec)
{
    printf("{ ");
    for(int i = 0; i < vec->size; i++)
    {
        printf("%f ",vec->data[i]);
    }
    printf(" }\n");
}

