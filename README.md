# Ruby-C-Extension

# Installation

ruby extconf.rb\
make

# Console

$ ruby -r "./test.so" -e 'p $a'\
or\
$ irb\
  : require_relative './test'\
  : $a\
  : $a.class
$ ruby extconf.rb && make && ruby -r "./test" -e "p string_test"
