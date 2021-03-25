#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_helper.h"
#include "test_vector.h"


int test_vector_new()
{
    int size = 100;
    Vector* testVec = vector_new(size);
    int resultSize = testVec->size;
    return (resultSize == size);
}

int test_vector_new_null()
{
    int size = 100;
    int compPass = 1;
    Vector* testVec = vector_new_null(size);
    for(int i = 0; i < size; i++)
    {
        if(testVec->data[i] != 0) { compPass = 0; }
    }
    int resultSize = testVec->size;
    return (resultSize == size && compPass == 1);
    //return (testVec->size == size && compPass == 1);
}

int test_vector_new_array()
{
    int size = 100;
    int compPass = 1;

    double* data = test_rand_double_array(size,-1000,1000);
    if(!data) { compPass = 0; size = 0; }
    Vector* testVec = vector_new_array(size,data);
    for(int i = 0; i < size; i++)
    {
        if(testVec->data[i] != data[i]) { compPass = 0; }
    }
    int resultSize = testVec->size;
    return (resultSize == size && compPass == 1);
}

int test_vector_copy()
{ 
    //(&*fVec != &*testVec)  - test for poiinter address is different - ensure no shallow copies.
    // change handling when new pointer data is null -set a flag instead so that I can 
    // differeniate between the test method failing, and the method we are testing failing.
    int size = 100;
    int compPass = 1;

    double* data = test_rand_double_array(size,-1000,1000);
    if(!data) { compPass = 0; size = 0; }
    Vector* fVec = vector_new_array(size,data);
    Vector* testVec = vector_copy(fVec);

    for(int i = 0; i < size; i++)
    {
        if(testVec->data[i] != data[i]) { compPass = 0; }
    }
    return ((fVec->size == testVec->size) && compPass == 1);
}

int test_vector_equal()
{
    double fData [5] = { 1,2,3,4,5 };
    double sData [5] = { 1,2,3,4,5 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_equal(fVec,sVec);
    return (val == 1);
}

int test_vector_not_equal()
{
    double fData [5] = { 1,2,3,4,5 };
    double sData [5] = { 1,2,3,4,6 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_not_equal(fVec,sVec);
    return (val == 1);
}

int test_vector_less()
{
    double fData [5] = { 0,0,0,0,0 };
    double sData [5] = { 1,2,3,4,5 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_less(fVec,sVec);
    return (val == 1);
}

int test_vector_greater()
{
    double fData [5] = { 2,3,4,5,6 };
    double sData [5] = { 1,2,3,0,5 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_greater(fVec,sVec);
    return (val == 1);
}

int test_vector_less_equal()
{
    double fData [5] = { 1,2,3,3,5 };
    double sData [5] = { 1,2,3,4,5 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_less_equal(fVec,sVec);
    return (val == 1);
}

int test_vector_greater_equal()
{
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    int val = vector_greater_equal(fVec,sVec);
    return (val == 1);
}

int test_vector_is_collinear()
{
    double fData [2] = {1,2};
    double sData [2] = {4,8};
    Vector* fVec = vector_new_array(2,fData);
    Vector* sVec = vector_new_array(2,sData);
    int val = vector_is_collinear(fVec,sVec);
    return (val == 1);
}

int test_vector_add()
{
    int compPass = 1;
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    double expected [5] = {2,4,6,10,10};
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    Vector* result = vector_add(fVec,sVec);

    for(int i = 0; i < 5; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

int test_vector_sub()
{
    int compPass = 1;
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    double expected [5] = {0,0,0,2,0};
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    Vector* result = vector_sub(fVec,sVec);

    for(int i = 0; i < 5; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

int test_vector_mult()
{
    int compPass = 1;
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    double expected [5] = {1,4,9,24,25};
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    Vector* result = vector_mult(fVec,sVec);

    for(int i = 0; i < 5; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

int test_vector_mult_scale()
{
    int compPass = 1;
    double data [5] = { 1,2,3,6,5 };
    double expected [5] = {2,4,6,12,10};
    Vector* vec = vector_new_array(5,data);
    Vector* result = vector_mult_scale(vec,2);
    for(int i = 0; i < 5; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

int test_vector_div()
{
    int compPass = 1;
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    double expected [5] = {1,1,1,1.5,1};
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    Vector* result = vector_div(fVec,sVec);

    for(int i = 0; i < 5; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

int test_vector_magnitude()
{
    double data [3] = { 4,5,8 };
    double expected = 10.246950765959598;
    Vector* vec = vector_new_array(3,data);
    double result = vector_magnitude(vec);
    return (result == expected);
}

// add in test for normalisation

int test_vector_dot()
{
    double fData [5] = { 1,2,3,6,5 };
    double sData [5] = { 1,2,3,4,5 };
    double expected = 63;
    Vector* fVec = vector_new_array(5,fData);
    Vector* sVec = vector_new_array(5,sData);
    double result = vector_dot(fVec,sVec);
    return (result == expected);
}

// add in dot angle test 

int test_vector_cross()
{
    int compPass = 1;
    double fData [3] = { 15.65,12,400 };
    double sData [3] = { 23.232325432,10,-234 };
    double expected [3] = {-6808, 12955.028, -122.28784 };
    Vector* fVec = vector_new_array(3,fData);
    Vector* sVec = vector_new_array(3,sData);
    Vector* result = vector_cross(fVec,sVec);

    for(int i = 0; i < 3; i++)
    {
        if(result->data[i] != expected[i]) { compPass = 0; }
    }
    return (compPass == 1);
}

void test_vector_run()
{
    srand(time(0));

    printf("---------- VECTOR TEST 1 [MEMORY] --------------\n");
    printf("[VECTOR NEW]        :   %s\n", (test_vector_new() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR NEW NULL]   :   %s\n", (test_vector_new() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR NEW ARRAY]  :   %s\n", (test_vector_new_array() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR COPY]       :   %s\n", (test_vector_copy() == 1) ? "PASS" : "FAIL");
    printf("\n"); 
    printf("---------- VECTOR TEST 2 [COMPARISON] ----------\n");
    printf("[VECTOR = ]         :   %s\n", (test_vector_equal() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR !=]         :   %s\n", (test_vector_not_equal() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR < ]         :   %s\n", (test_vector_less() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR > ]         :   %s\n", (test_vector_greater() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR <=]         :   %s\n", (test_vector_less_equal() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR >=]         :   %s\n", (test_vector_greater_equal() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR COLLINEAR]  :   %s\n", (test_vector_is_collinear() == 1) ? "PASS" : "FAIL");
    printf("\n"); 
    printf("---------- VECTOR TEST 3 [MATH] ----------------\n");
    printf("[VECTOR +]          :   %s\n", (test_vector_add() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR -]          :   %s\n", (test_vector_sub() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR *]          :   %s\n", (test_vector_mult() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR *]          :   %s\n", (test_vector_mult_scale() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR /]          :   %s\n", (test_vector_div() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR MAGNITUDE]  :   %s\n", (test_vector_magnitude() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR DOT]        :   %s\n", (test_vector_dot() == 1) ? "PASS" : "FAIL");
    printf("[VECTOR CROSS]      :   %s\n", (test_vector_cross() == 1) ? "PASS" : "FAIL");
    printf("-----------------------------------\n");
}