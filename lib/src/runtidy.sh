#!/bin/sh

if [ $# -lt 1 ]; then
echo "Need a file name"
exit 1
fi

clang-tidy -extra-arg=-std=c++17 -header-filter='.*' -p ../build $1

# without the database. But I have cmake generate one in build.
#clang-tidy -extra-arg=-std=c++17 -header-filter='.*' $1 -- -I ../include -I /Library/Developer/CommandLineTools/usr/include/c++/v1 

# http://clang.llvm.org/extra/clang-tidy/
