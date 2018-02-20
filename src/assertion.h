#pragma once

#include <stdlib.h>

#define assert_exit_(cond)                            \
   do {                                               \
      if( ! (cond) ) {                                \
         fprintf(stderr,                              \
                 "assertion (%s) failed in %s:%d\n",  \
                 #cond, __FILE__, __LINE__);          \
         exit(1);                                     \
      }                                               \
   } while(false)
