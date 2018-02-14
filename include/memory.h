#pragma once

#include <stddef.h>
#include <stdbool.h>

void* memalloc(size_t num, size_t size, bool failure, const char* file, int line);
void memfree(void* p);

#define memalloc_(num,size) memalloc(num,size,false,__FILE__,__LINE__)
