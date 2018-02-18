#include <stdio.h>
#include "list.h"
#include "memory.h"

typedef struct IntList IntList;
struct IntList {
   int x;
   List list;
};

int main() {
   List head;
   list_init_(&head);
   int xs[8] = {0, 1, 2, 3, 4, 5, 6, 7};

   for(int i = 0; i < 8; ++i) {
      IntList *p = memalloc_(1,sizeof(IntList));
      p->x = xs[i];
      list_push_back_(&head, &p->list);
   }

   int i = 0;

   list_for_(IntList,list,p,&head) {
      if( i >= 8 )
         return 1;

      if( p->x != xs[i] )
         return 1;

      i += 1;
   }

   list_for_(IntList,list,p,&head) {
      memfree(p);
   }

   return 0;
}
