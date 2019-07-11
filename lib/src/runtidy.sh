#!/bin/sh

clang-tidy -extra-arg=-std=c++17 -header-filter='.*' $1 -- -I../include -I/Library/Developer/CommandLineTools/usr/include/c++/v1
