#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include "memory.h"

void* memalloc(size_t num, size_t size, bool failure, const char* file, int line) {
   void* p = calloc(num, size);
   if( p == NULL || failure ) {
      abort();
   }
   (void)file;
   (void)line;
   return p;
}

void memfree(void* p) {
   free(p);
}
