#include "string_builder.h"

int test_string_builder_create_delete(void) {
   StringBuilder *builder = create_string_builder();
   delete_string_builder(builder);
   return 0;
}

int test_string_builedr_generate_cstring_1(void) {
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

const int num_tests = 2;
int(*test_functions[])(bool) = {
   test_string_builder_create_delete,
   test_string_builder_generate_cstring_1,
};
const char *test_names[] = {
   "create_delete",
   "generate_cstring_1",
};

int main(int argc, char *argv[]) {
   for(int i = 0; i < num_tests; ++i) {
      if( strcmp(argv[1], test_names[i]) == 0 )
         return test_functions[i]();
   }

   return 1;
}
