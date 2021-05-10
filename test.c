#include "ruby.h"

// Init function name must be followed with 
// the name from extconf.rb file in 'create_makefile' method
void Init_test() {
  // in C it would look like int *a = "abcd", but in ruby everythig is VALUE
  
  VALUE abcd = rb_str_new_cstr("Abcd");
  VALUE abcd2 = rb_str_new_literal("\e[5mRUBY\e[0m"); // we can use 'literal' instead of 'cstr', string blinks when 'puts'

  // when we want to pass length of String
  // VALUE abcd = rb_str_new("Abcd", 4);

  rb_gv_set("$a", rb_str_new_cstr("abcd")); // global String variable, rb_str_new_cstr(*char)

  // rb_gv_set("$b", &abcd);
  // VALUE is garbage collected, so we must be very careful, because it can crash an entire program
  rb_global_variable(&abcd);

  rb_gv_set("$b", abcd);
  rb_gv_set("$c", abcd2);
}
