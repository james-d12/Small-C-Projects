/*************************************************************************
Copyright 2019 James Durban

The file 'vector_comp.c' is apart of the 'clib-linear-algebra' library, 
and contains a variety of comparison function definitions such as equals, 
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

#include "vector_comp.h"
#include "vector_math.h"
#include "lalgebra_errors.h"

int vector_equal(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    int res = 1;
    for(int i = 0; i < fVec->size; i++)
    {
        if(fVec->data[i] != sVec->data[i]) { res = 0; }
    }
    return res;
}

int vector_not_equal(Vector* fVec, Vector* sVec)
{
    return !vector_equal(fVec,sVec);
}

int vector_less(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    int res = 1;
    for(int i = 0; i < fVec->size; i++)
    {
        if(fVec->data[i] >= sVec->data[i]) { res = 0; }
    }
    return res;
}

int vector_greater(Vector* fVec, Vector* sVec)
{
    return vector_less(sVec,fVec);
}

int vector_less_equal(Vector* fVec, Vector* sVec)
{
    return !vector_greater(fVec,sVec);
}

int vector_greater_equal(Vector* fVec, Vector* sVec)
{
    return !vector_less(fVec,sVec);
}

int vector_is_collinear(Vector* fVec, Vector* sVec)
{
    double dotProduct = vector_dot(fVec,sVec);
    return (dotProduct == 0);
}

int vector_orthogonal(Vector* fVec, Vector* sVec)
{
    double dotProduct = vector_dot(fVec,sVec);
    return (dotProduct == 0);
}

int vector_is_coplanar(Vector* fVec, Vector* sVec, Vector* tVec)
{
    double scalarTripletProduct = vector_scalar_triplet_product(fVec,sVec,tVec);
    return (scalarTripletProduct == 0);
}
