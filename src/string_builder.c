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

   list_free_(CharList, head, &builder->head);
   memfree(builder);
}
