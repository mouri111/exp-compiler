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

#define list_for_(T,list,p,head)                               \
   for(T *p = (T*)((size_t)((head)->next)-offsetof(T,list));   \
       &p->list != head;                                       \
       p = (T*)((size_t)(p->list.next)-offsetof(T,list)))
