#include "assertion.h"

int main(int argc, char *argv[]) {
   (void)argv;
   assert_exit_(argc == 1);
   return 0;
}
