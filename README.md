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
