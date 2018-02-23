#include "string_builder.h"
#include "list.h"
#include "memory.h"

typedef struct CharList CharList;
struct CharList {
   List list;
   char c;
};

struct StringBuilder {
   List head;
};

StringBuilder* create_string_builder(void) {
   StringBuilder *p = memalloc_(1, sizeof(StringBuilder));
   list_init(&p->head);
   return p;
}

void delete_string_builder(StringBuilder *builder) {
   if( builder == NULL )
      return;

   list_free_(CharList, list, &builder->head);
   memfree(builder);
}

void string_builder_push_front(StringBuilder *builder, char c) {
   CharList *p = memalloc_(1, sizeof(CharList));
   p->c = c;
   list_push_front(&builder->head, &p->list);
}

void string_builder_push_back(StringBuilder *builder, char c) {
   CharList *p = memalloc_(1, sizeof(CharList));
   p->c = c;
   list_push_back(&builder->head, &p->list);
}

char string_builder_pop_front(StringBuilder *builder) {
   List *p = list_pop_front(&builder->head);
   CharList *q = list_parent_(CharList, list, p);
   char c = q->c;
   memfree(q);
   return c;
}

char string_builder_pop_back(StringBuilder *builder) {
   List *p = list_pop_back(&builder->head);
   CharList *q = list_parent_(CharList, list, p);
   char c = q->c;
   memfree(q);
   return c;
}

char* string_builder_generate_cstring(StringBuilder *builder) {
}
