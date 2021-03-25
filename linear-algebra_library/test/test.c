
#include "vector.h"
#include "matrix.h"

#include "test_vector.h"

#include <stdio.h>

int main()
{
    double newMat3Data [9] = 
    {
        1,2,3,
        4,5,6,
        7,8,9
    };


    Matrix* newMat = matrix_new_null(5,6,COLUMN_MAJOR);
    Matrix* newMat2 = matrix_new_identity(3);
    Matrix* newMat3 = matrix_new(3,3,ROW_MAJOR,newMat3Data);

    matrix_print(newMat3);
    matrix_resize(newMat,3,3);
    printf("\n");
    matrix_print(newMat);


    newMat = matrix_copy_column(newMat3,3);

    printf("\n");
    matrix_print(newMat);
    printf("\n");
    matrix_print(newMat2);

    matrix_delete(&newMat);
    //test_vector_run();
    return 0;
}