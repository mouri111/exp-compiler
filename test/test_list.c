#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "memory.h"

typedef struct IntList IntList;
struct IntList {
   int x;
   List list;
};

int test_list_push_back(bool failure) {
   List head;
   list_init(&head);
   int xs[8] = {0, 1, 2, 3, 4, 5, 6, 7};

   for(int i = 0; i < 8; ++i) {
      IntList *p = memalloc_(1,sizeof(IntList));
      p->x = xs[i];
      list_push_back(&head, &p->list);
   }

   int i = 0;
   int res = failure ? 1 : 0;

   list_for_(IntList,list,p,&head) {
      if( i >= 8 ) {
         res = 1;
         break;
      }

      if( p->x != xs[i] ) {
         res = 1;
         break;
      }

      i += 1;
   }

   if( i != 8 )
      res = 1;

   list_free_(IntList,list,&head);

   return res;
}

int test_list_push_front(bool failure) {
   List head;
   list_init(&head);
   int xs[8] = {0, 1, 2, 3, 4, 5, 6, 7};

   for(int i = 0; i < 8; ++i) {
      IntList *p = memalloc_(1,sizeof(IntList));
      p->x = xs[i];
      list_push_front(&head, &p->list);
   }

   int i = 0;
   int res = failure ? 1 : 0;

   list_for_(IntList,list,p,&head) {
      if( i >= 8 ) {
         res = 1;
         break;
      }

      if( p->x != xs[8-i-1] ) {
         res = 1;
         break;
      }

      i += 1;
   }

   if( i != 8 )
      res = 1;

   list_free_(IntList,list,&head);

   return res;
}

const int num_tests = 2;
int(*test_functions[])(bool) = {
   test_list_push_back,
   test_list_push_front,
};
const char *test_names[] = {
   "push_back",
   "push_front",
};

int main(int argc, char *argv[]) {
   if( ! ( argc != 2 || ( argc == 3 && strcmp(argv[2], "failure") == 0 ) ) )
      return 1;

   bool failure = argc == 3;

   for(int i = 0; i < 2; ++i) {
      if( strcmp(argv[1], test_names[i]) == 0 )
         test_functions[i](failure);
   }

   return 1;
}
