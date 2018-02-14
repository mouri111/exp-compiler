#pragma once

void* memalloc(size_t num, size_t size, const char* file, int line);
void memfree(void* p);
