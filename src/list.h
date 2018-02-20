#pragma once

#include <stddef.h>

typedef struct List List;
struct List {
   List *prev, *next;
};


void list_init(List *head);

void list_push_front(List *head, List *p);
void list_push_back(List *head, List *p);

List* list_pop_front(List *head) __attribute__((warn_unused_result));
List* list_pop_back(List *head) __attribute__((warn_unused_result));

#define list_parent_(T,list,p)                  \
   (T*)((size_t)(p)-offsetof(T,list))

#define list_for_(T,list,p,head)                   \
   for(T *p = list_parent_(T,list,(head)->next);   \
       &p->list != head;                           \
       p = list_parent_(T,list,p->list.next))

#define list_free_(T,list,head)                 \
   do {                                         \
      List *p = list_pop_front(head);           \
      while( p != NULL ) {                      \
         T *q = list_parent_(T,list,p);         \
         memfree(q);                            \
         p = list_pop_front(head);              \
      }                                         \
   } while(false)
