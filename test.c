#include "ruby.h"

// Init function name must be followed with 
// the name from extconf.rb file in 'create_makefile' method
void Init_test() {
  rb_gv_set("$a", rb_str_new_cstr("abcd")); // global String variable, rb_str_new_cstr(*char)
}
