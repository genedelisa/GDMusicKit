#!/bin/sh

clang-tidy -p ../build -fix $1

#clang-tidy -p ../build -fix -checks="llvm-header-guard" Note.cpp
