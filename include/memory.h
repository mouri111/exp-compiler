#pragma once

#include <stddef.h>

void* memalloc(size_t num, size_t size, const char* file, int line);
void memfree(void* p);
