#pragma once

#include <stddef.h>

typedef struct List List;
struct List {
   List *prev, *next;
};

#define list_init_(head)                        \
   do {                                          \
      (head)->prev = (head);                     \
      (head)->next = (head);                     \
   } while(false)

#define list_push_front_(head,p)                \
   do {                                         \
      List *next = (head)->next;                \
      (head)->next = (p);                       \
      (p)->prev = (head);                       \
      (p)->next = next;                         \
      next->prev = (p);                         \
   } while(false)

#define list_push_back_(head,p)                 \
   do {                                         \
      List* prev = (head)->prev;                \
      (head)->prev = (p);                       \
      (p)->next = (head);                       \
      (p)->prev = prev;                         \
      prev->next = (p);                         \
   } while(false)

#define list_for_(T,list,p,head)                            \
   for(T *p = (T*)((size_t)((head)->next)-offsetof(T,list));   \
       &p->list != head;                                    \
       p = (T*)((size_t)(p->list.next)-offsetof(T,list)))
