#ifndef _DL_MEMORY_H
#define _DL_MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

extern size_t memAllocated;

void* internal_dl_memory_malloc(size_t size, const char* file, unsigned int line, const char* time);
void* internal_dl_memory_realloc(void* block, size_t size, const char* file, unsigned int line, const char* time);
void* internal_dl_memory_calloc(size_t count, size_t size, const char* file, unsigned int line, const char* time);
void  internal_dl_memory_free(void* blk, const char* file, unsigned int line, const char* time);

int   internal_dl_memory_memcmp(const void* block1, const void* block2, size_t count, const char* file, unsigned int line);
void* internal_dl_memory_memset(void* dest, int value, size_t size, const char* file, unsigned int line);
void* internal_dl_memory_memove(void* dest, const void* src, size_t size, const char* file, unsigned int line);
void* internal_dl_memory_memcpy(void* dest, const void* src, size_t size, const char* file, unsigned int line);

#define DL_MEMORY_MALLOC(size) internal_dl_memory_malloc(size,__FILE__,__LINE__,__TIME__);
#define DL_MEMORY_REALLOC(block,size) internal_dl_memory_realloc(block,size,__FILE__,__LINE__,__TIME__);
#define DL_MEMORY_CALLOC(count,size) internal_dl_memory_calloc(count,size,__FILE__,__LINE__,__TIME__);
#define DL_MEMORY_FREE(blk) internal_dl_memory_free(blk,__FILE__,__LINE__,__TIME__);

#define DL_MEMORY_MEMCMP(blk1,blk2,count) internal_dl_memory_memcmp(blk1,blk2,count,__FILE__,__LINE__);
#define DL_MEMORY_MEMSET(dest,value,size) internal_dl_memory_memset(dest,value,size,__FILE__,__LINE__);
#define DL_MEMORY_MEMOVE(dest,src,size) internal_dl_memory_memove(dest,src,size,__FILE__,__LINE__);
#define DL_MEMORY_MEMCPY(dest,src,size) internal_dl_memory_memcpy(dest,src,size,__FILE__,__LINE__);

#endif