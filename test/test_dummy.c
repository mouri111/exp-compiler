#include <stdio.h>
#include "dummy.h"

int main() {
   for(int i = 0; i < 10; ++i) {
      for(int k = 0; k < 10; ++k) {
         if( dummy(i,k) != i+k ) {
            return 1;
         }
      }
   }
   return 0;
}
