#include "ruby.h"

// functions declarations
VALUE string_test();
VALUE integer_test();
VALUE float_test();
VALUE boolean_test();


// Init function name must be followed with 
// the name from extconf.rb file in 'create_makefile' method
void Init_test() {

  rb_define_global_function("string_test", string_test, 0);
  rb_define_global_function("integer_test", integer_test, 0);
  rb_define_global_function("float_test", float_test, 0);
  rb_define_global_function("boolean_test", boolean_test, 0);
}


VALUE string_test() {

  // in C it would look like int *a = "abcd", but in ruby everythig is VALUE

// we can use 'literal' instead of 'cstr', string blinks when 'puts'
  VALUE abcd = rb_str_new_cstr("Abcd");
  VALUE abcd2 = rb_str_new_literal("\e[5mRUBY\e[0m"); 
  rb_p(abcd);

  // when we want to pass length of String
  // VALUE abcd = rb_str_new("Abcd", 4);

  rb_gv_set("$a", rb_str_new_cstr("abcd")); // global String variable, rb_str_new_cstr(*char)

  // rb_gv_set("$b", &abcd);
  // VALUE is garbage collected, so we must be very careful, because it can crash an entire program
  rb_global_variable(&abcd);

  rb_gv_set("$b", abcd);
  rb_gv_set("$c", abcd2);

  return rb_str_new_cstr("string_test method");
}

VALUE integer_test() {

  // In irb console 250.object_id == 501
  // VALUE numx = 28;
  // rb_p(numx); // prints 250 instead of 501, 28 dumps core. Stay away from this declaration

  VALUE num = INT2FIX(501);
  rb_p(num);
  VALUE big_num = INT2NUM(2147483647);
  rb_p(big_num);
  VALUE u_big_num = UINT2NUM(4294967295U);
  rb_p(u_big_num);

  int a = 5;
  VALUE av = INT2FIX(a);
  rb_p(av);
  unsigned int b = 6;
  VALUE bv1 = INT2NUM(b);
  VALUE bv2 = INT2FIX(b);
  VALUE bv3 = UINT2NUM(b); // there is no UINT2FIX 

  rb_p(bv1);
  rb_p(bv2);
  rb_p(bv3);

  long c = 7;
  VALUE cv = LONG2NUM(c);
  rb_p(cv);

  unsigned long d = 8;
  VALUE dv = ULONG2NUM(d);
  rb_p(dv);

  unsigned long long e = 9;
  VALUE ev = ULL2NUM(e);
  rb_p(ev);

  long long f = 9;
  VALUE fv = LL2NUM(f);
  rb_p(fv);

  return rb_str_new_cstr("integer_test method");
}

VALUE float_test() {

  VALUE af = rb_float_new(2.123);
  rb_p(af);

  double d = 1234567890.1234567890;
  VALUE df = rb_float_new(d); //can cause bugs
  rb_p(df); // 1234567890.1234567
  VALUE ddf = DBL2NUM(d); // correct way to convert
  rb_p(ddf); // 1234567890.1234567

  // if big numbers needed we have to use string, mpfr/gmp library

  return rb_str_new_cstr("float_test method");
}

VALUE boolean_test() {

  VALUE x = Qnil;
  rb_p(x); // nil
  // Qtrue/number except 8 | Qfalse/0 | Qnil/8

  VALUE arg = Qfalse, str; // "Arg is false!"
  // VALUE arg = INT2FIX(5000), str; // "The value pf arg is: 5000"
  // VALUE arg = rb_ary_new(), str; // "The value pf arg is: []"
  // VALUE arg = rb_hash_new(), str; // "The value pf arg is: {}"

  if(arg) {
    VALUE str_arg = rb_funcall(arg, rb_intern("to_s"), 0); // convert arg to string
    char *string = StringValuePtr(str_arg);
    char buf[1000];
    sprintf(buf, "The value pf arg is: %s", string);
    str = rb_str_new_cstr(buf);
  } else {
    str = rb_str_new_cstr("Arg is false!");
  }

  rb_p(str);

  return rb_str_new_cstr("boolean_test method");
}
