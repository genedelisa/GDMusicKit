#!/bin/sh

cppcheck --std=c++17 --enable=all -I../include $1

# cppcheck . --std=c++17 --language=c++ --xml --suppressions-list=suppressions.txt 2> cppcheck-result.xml

#--enable=all
#--enable=warning
#--enable=style
#--enable=performance
#--enable=portability
#--enable=information
#--enable=unusedFunction
#--enable=missingInclude
