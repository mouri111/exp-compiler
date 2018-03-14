#include <string.h>
#include "string_builder.h"
#include "assertion.h"
#include "memory.h"

int test_string_builder_create_delete(void) {
   StringBuilder *builder = create_string_builder();
   delete_string_builder(builder);
   return 0;
}

int test_string_builder_generate_cstring_1(void) {
   StringBuilder *builder = create_string_builder();
   const char* str = "abcdefgh";
   int len = strlen(str);

   for(int i = 0; i < len; ++i)
      string_builder_push_back(builder, str[i]);

   char* str2 = string_builder_generate_cstring(builder);
   assert_exit_( strcmp(str,str2) == 0 );
   memfree(str2);

   delete_string_builder(builder);

   return 0;
}

int test_string_builder_pop_front(void) {
   StringBuilder *builder = create_string_builder();
   const char* str = "abcdefdh";
   int len = strlen(str);

   for(int i = 0; i < len; ++i)
      string_builder_push_back(builder, str[i]);

   for(int i = 0; i < len; ++i) {
      char c = string_builder_pop_front(builder);
      assert_exit_( c == str[i] );
      char *str2 = string_builder_generate_cstring(builder);
      assert_exit_( strncmp(str+i+1,str2,len-i-1) == 0 );
      memfree(str2);
   }

   char c = string_builder_pop_front(builder);
   assert_exit_( c == '\0' );
   delete_string_builder(builder);
   return 0;
}

int test_string_builder_pop_back(void) {
   StringBuilder *builder = create_string_builder();
   const char* str = "abcdefgh";
   int len = strlen(str);

   for(int i = 0; i < len; ++i)
      string_builder_push_back(builder, str[i]);

   for(int i = 0; i < len; ++i) {
      char c = string_builder_pop_back(builder);
      assert_exit_( c == str[len-i-1] );
      char *str2 = string_builder_generate_cstring(builder);
      assert_exit_( strncmp(str, str2, len-i-1) == 0 );
      memfree(str2);
   }

   char c = string_builder_pop_back(builder);
   assert_exit_( c == '\0' );
   delete_string_builder(builder);
   return 0;
}

const int num_tests = 4;
int(*test_functions[])(void) = {
   test_string_builder_create_delete,
   test_string_builder_generate_cstring_1,
   test_string_builder_pop_front,
   test_string_builder_pop_back,
};
const char *test_names[] = {
   "create_delete",
   "generate_cstring_1",
   "pop_front",
   "pop_back",
};

int main(int argc, char *argv[]) {
   assert_exit_( argc == 2 );

   for(int i = 0; i < num_tests; ++i) {
      if( strcmp(argv[1], test_names[i]) == 0 )
         return test_functions[i]();
   }

   return 1;
}
