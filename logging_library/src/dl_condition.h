#ifndef _DL_CONDITION_H
#define _Dl_CONDITION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void internal_check_and_handle_divide_by_zero(unsigned int line, const char* file, int howMany, ...);
int  internal_check_and_handle_integer_overflow(unsigned int line, const char* file, int a, int b);
void internal_check_and_handle_null_pointer(unsigned int line, const char* file, void* ptr);
void internal_check_and_handle_index_out_of_range(unsigned int line, const char* file, int index, int size);


#define CHECK_AND_HANDLE_DIVIDE_BY_ZERO(howMany,...) \
internal_check_and_handle_divide_by_zero(__LINE__,__FILE__,howMany,__VA_ARGS__);
#define CHECK_AND_HANDLE_INTEGER_OVERFLOW(a,b) \
internal_check_and_handle_divide_by_zero(__LINE__,__FILE__,a,b);
#define CHECK_AND_HANDLE_NULL_POINTER(ptr) \
internal_check_and_handle_null_pointer(__LINE__,__FILE__,ptr);
#define CHECK_AND_HANDLE_INDEX_OUT_OF_RANGE(index,size) \
internal_check_and_handle_index_out_of_range(__LINE__,__FILE__,index,size);

#endif
