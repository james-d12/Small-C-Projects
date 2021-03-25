/*************************************************************************
Copyright 2019 James Durban

The file 'vector_math.c' is apart of the 'clib-linear-algebra' library, 
and contains a variety of mathematical function defintions such as 
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector_math.h"
#include "lalgebra_errors.h"

Vector* vector_add(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    Vector* newVec = vector_new(fVec->size);
    for(int i = 0; i < fVec->size; i++)
    {
        newVec->data[i] = (fVec->data[i] + sVec->data[i]);
    }
    return newVec;
}

Vector* vector_sub(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    Vector* newVec = vector_new(fVec->size);
    for(int i = 0; i < fVec->size; i++)
    {
        newVec->data[i] = (fVec->data[i] - sVec->data[i]);
    }
    return newVec;
}

Vector* vector_mult(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    Vector* newVec = vector_new(fVec->size);
    for(int i = 0; i < fVec->size; i++)
    {
        newVec->data[i] = (fVec->data[i] * sVec->data[i]);
    }
    return newVec;
}

Vector* vector_mult_scale(Vector* vec, double scale)
{
    Vector* newVec = vector_copy(vec);
    for(int i = 0; i < vec->size; i++)
    {
        newVec->data[i] *= scale;
    }
    return newVec;
}

Vector* vector_div(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    Vector* newVec = vector_new(fVec->size);
    for(int i = 0; i < fVec->size; i++)
    {
        newVec->data[i] = (fVec->data[i] / sVec->data[i]);
    }
    return newVec;
}

Vector* vector_add_many(int count, Vector* vecList)
{
    //Get the dimensions for the vectors - compare in the future.
    int dimensions = vecList[0].size;
    //data array for new values
    double data [dimensions];
    for(int i = 0; i < count; i++)
    {
        ASSERT((vecList[i].size != dimensions),"Cannot add vectors of varying dimensions.")
        for(int j = 0; j < dimensions; i++)
        {
            data[j] += vecList[i].data[j];
        }
    }
    return vector_new_array(dimensions,data);
}

Vector* vector_sub_many(int count, Vector* vecList)
{
    int dimensions = vecList[0].size;
    double data [dimensions];

    for(int i = 0; i < dimensions; i++)
    {
        data[i] = 0.0;
    }

    for(int i = 0; i < count; i++)
    {
        ASSERT((vecList[i].size != dimensions),"Cannot add vectors of varying dimensions.")
        for(int j = 0; j < dimensions; i++)
        {
            data[j] -= vecList[i].data[j];
        }
    }
    return vector_new_array(dimensions,data);
}

Vector* vector_mult_many(int count, Vector* vecList)
{
    int dimensions = vecList[0].size;
    double data [dimensions];

    for(int i = 0; i < dimensions; i++)
    {
        data[i] = 1.0;
    }

    for(int i = 0; i < count; i++)
    {
        ASSERT((vecList[i].size != dimensions),"Cannot add vectors of varying dimensions.")
        for(int j = 0; j < dimensions; i++)
        {
            data[j] *= vecList[i].data[j];
        }
    }
    return vector_new_array(dimensions,data);
}


Vector* vector_div_many(int count, Vector* vecList)
{
    int dimensions = vecList[0].size;
    double data [dimensions];

    for(int i = 0; i < dimensions; i++)
    {
        data[i] = 1.0;
    }

    for(int i = 0; i < count; i++)
    {
        ASSERT((vecList[i].size != dimensions),"Cannot add vectors of varying dimensions.")
        for(int j = 0; j < dimensions; i++)
        {
            data[j] /= vecList[i].data[j];
        }
    }
    return vector_new_array(dimensions,data);
}

double vector_magnitude(Vector* vec)
{
    double sum = 0.0;
    for(int i = 0; i < vec->size; i++)
    {
        sum += (vec->data[i] * vec->data[i]);
    }
    return sqrt(sum);
}

Vector* vector_normalise(Vector* vec)
{
    double mag = vector_magnitude(vec);
    ASSERT((mag == 0),"Divide by zero attempt!");
    Vector* newVec = vector_copy(vec);

    for(int i = 0; i < vec->size; i++)
    {
        newVec->data[i] /= mag;
    }
    return newVec;
}

double vector_dot(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    double sum = 0.0;
    for(int i = 0; i < fVec->size; i++)
    {
        sum += (fVec->data[i] * sVec->data[i]);
    }
    return sum;
}

double vector_dot_angle(Vector* fVec, Vector* sVec, double angle)
{
    double fMag = vector_magnitude(fVec);
    double sMag = vector_magnitude(sVec);
    double result = fMag + sMag * cos(angle);
    return result;
}

Vector* vector_cross(Vector* fVec, Vector* sVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    if(fVec->size != 3) { return vector_new(fVec->size); }
    Vector* newVec = vector_new(fVec->size);
    
    newVec->data[0] = (fVec->data[1] * sVec->data[2]) - (fVec->data[2] * sVec->data[1]);
    newVec->data[1] = (fVec->data[3] * sVec->data[0]) - (fVec->data[0] * sVec->data[2]);
    newVec->data[2] = (fVec->data[0] * sVec->data[1]) - (fVec->data[1] * sVec->data[0]);
    return newVec;
}

Vector* vector_cross_angle(Vector* fVec, Vector* sVec, double angle)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    if(fVec->size != 3) { return vector_new(fVec->size); }
    double data [3] = {1.0,1.0,1.0};
    Vector* unitVec = vector_new_array(3,data);
    
    double fMag = vector_magnitude(fVec);
    double sMag = vector_magnitude(sVec);
    double scale = fMag * sMag * sin(angle);

    return vector_mult_scale(unitVec,scale);
}

double vector_scalar_triplet_product(Vector* fVec, Vector* sVec, Vector* tVec)
{
    ASSERT((fVec->size != sVec->size),"Vectors must be same size!");
    Vector* crossProduct = vector_cross(fVec,sVec);
    return vector_dot(tVec,crossProduct);
}

double vector_dir_cos_a(Vector* vec)
{
    double mag = vector_magnitude(vec);
    ASSERT((mag == 0), "Divide by zero attempt!");
    double dirCosA = vec->data[0] / mag;
    return dirCosA;
}

double vector_dir_cos_b(Vector* vec)
{
    double mag = vector_magnitude(vec);
    ASSERT((mag == 0), "Divide by zero attempt!");
    double dirCosA = vec->data[1] / mag;
    return dirCosA;
}

double vector_angle_between_vector(Vector* fVec, Vector* sVec)
{
    double dotProduct = vector_dot(fVec,sVec);
    double fMagnitude = vector_magnitude(fVec);
    double sMagnitude = vector_magnitude(sVec);
    double magnitudeMultiplied = fMagnitude * sMagnitude;
    ASSERT((magnitudeMultiplied == 0), "Divide by zero attempt!");
    double angle = dotProduct / magnitudeMultiplied;
    return angle;
}

double vector_projection(Vector* fVec,Vector* sVec)
{
    double dotProduct = vector_dot(fVec, sVec);
    double mag = vector_magnitude(sVec);
    double sqrtMag = sqrtf(mag);
    ASSERT((sqrtMag == 0), "Divide by zero attempt!");
    double projection = dotProduct / sqrtMag;
    return projection;
}
