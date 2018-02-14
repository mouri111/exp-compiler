#include "memory.h"

void* memalloc(size_t num, size_t size, const char* file, int line) {
   (void)num;
   (void)size;
   (void)file;
   (void)line;
   return NULL;
}

void memfree(void* p) {
   (void)p;
}
