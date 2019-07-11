#!/bin/sh

cppcheck --std=c++17 --enable=all -I../include $1

# cppcheck . --std=c++17 --language=c++ --xml --suppressions-list=suppressions.txt 2> cppcheck-result.xml

