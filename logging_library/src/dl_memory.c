#include "dl_memory.h"

size_t memAllocated = 0;

void* internal_dl_memory_malloc(size_t size, const char* file, unsigned int line, const char* time) 
{
	printf("[DEBUG]: %zu bytes allocated. | FILE: %s | LINE: %d | TIME: %s\n", size, file, line,time);
	memAllocated += size;
	return malloc(size);
}
void* internal_dl_memory_realloc(void* block, size_t size, const char* file, unsigned int line, const char* time)
{
	printf("[DEBUG]: %zu bytes re-allocated. | FILE: %s | LINE: %d | TIME %s\n", size, file, line, time);
	memAllocated += size;
	return realloc(block,size);
}
void* internal_dl_memory_calloc(size_t count, size_t size, const char* file, unsigned int line, const char* time)
{
	printf("[DEBUG]: %zu bytes 'c-allocated'. | FILE: %s | LINE: %d | TIME: %s\n", size, file, line, time);
	memAllocated += size;
	return calloc(count, size);
}
void  internal_dl_memory_free(void* block, const char* file, unsigned int line, const char* time)
{
	printf("[DEBUG]: Memory freed. | FILE: %s | LINE: %d | TIME: %s\n", file, line,time);
	free(block);
}

int   internal_dl_memory_memcmp(const void* block1, const void* block2, size_t count, const char* file, unsigned int line)
{
	printf("[DEBUG]: Memory compared. | FILE: %s | LINE: %d\n", file, line);
	return memcmp(block1, block2, count);
}
void* internal_dl_memory_memset(void* dest, int value, size_t size, const char* file, unsigned int line)
{
	printf("[DEBUG]: %zu Bytes copied CH into memory destination. | FILE: %s | LINE: %d\n", size,file, line);
	memAllocated += size;
	return memset(dest, value, size);
}
void* internal_dl_memory_memove(void* dest, const void* src, size_t size, const char* file, unsigned int line)
{
	printf("[DEBUG]: %zu Bytes moved from source to destination. | FILE: %s | LINE: %d\n", size, file, line);
	memAllocated += size;
	return memmove(dest, src, size);
}
void* internal_dl_memory_memcpy(void* dest, const void* src, size_t size, const char* file, unsigned int line)
{
	printf("[DEBUG]: %zu Bytes copied from source to destination. | FILE: %s | LINE: %d\n", size, file, line);
	memAllocated += size;
	return memcpy(dest, src, size);
}
