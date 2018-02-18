#include "list.h"

void list_init(List *head) {
   head->prev = head;
   head->next = head;
}

void list_push_front(List *head, List *p) {
   List *next = head->next;
   head->next = p;
   p->prev = head;
   p->next = next;
   next->prev = p;
}

void list_push_back(List *head, List *p) {
   List *prev = head->prev;
   head->prev = p;
   p->next = head;
   p->prev = prev;
   prev->next = p;
}

List* list_pop_front(List *head) {
   if( head->next == head )
      exit(1);
   List *res = head->next;
   List *p = head->next->next;
   head->next = p;
   p->prev = head;
   return res;
}

List* list_pop_back(List *head) {
   if( head->prev == head )
      exitt(1);
   List *res = head->prev;
   List *p = head->prev->prev;
   head->prev = p;
   p->next = head;
   return res;
}
