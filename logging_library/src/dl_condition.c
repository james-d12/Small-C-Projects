#include "dl_condition.h"

void internal_check_and_handle_divide_by_zero(unsigned int line, const char* file, int howMany, ...)
{
    va_list numArgumentPtr;
    va_start( numArgumentPtr, howMany);
    for(int i = 0; i < howMany; i++)
    {
        if(va_arg(numArgumentPtr,double) == 0)
        {
            printf("[ERROR]: Divide by zero error occured! | FILE: %s | LINE: %d\n",file,line);
            va_end(numArgumentPtr);
            exit(EXIT_FAILURE);
        }
    }

    va_end(numArgumentPtr);
}
int internal_check_and_handle_integer_overflow(unsigned int line, const char* file, int a, int b)
{
    int sum = 0;

    if (a > 0 && b > INT_MAX - a) 
    {
        sum = INT_MAX;
        printf("[WARNING]: Integer overflow occured! | FILE: %s | LINE: %d\n", file,line);
    } 
    else if (a < 0 && b < INT_MIN - a) 
    {
        sum = INT_MIN;
        printf("[WARNING]: Integer underflow occured! | FILE: %s | LINE: %d\n", file,line);
    }
    else
    {
        sum = a + b;
    }

    return sum;
}
void internal_check_and_handle_null_pointer(unsigned int line, const char* file, void* ptr)
{
    if(!ptr)
    {
        printf("[WARNING]: Null pointer detected! | FILE: %s | LINE: %d\n",file,line);
    }
}
void internal_check_and_handle_index_out_of_range(unsigned int line, const char* file, int index, int size)
{
    if(index > size || index < 0)
    {
        printf("[ERROR] Index out of range! | FILE: %s | LINE: %d\n",file,line);
    }
}
