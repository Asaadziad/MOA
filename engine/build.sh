#!/usr/bin/bash 

set echo on

mkdir -p ../bin

cFilenames=$(find . -type f -name "*.cpp")

assembly="engine"
compilerFlags="-g -shared -fdeclspec -fPIC"

includeFlags="-Isrc"
linkedFlags="-lraylib -lGL -lrt -lm"
defines=""

echo "Building $assembly..."
clang++ $cFilenames $compilerFlags -o ../bin/lib$assembly.so $defines $includeFlags $linkedFlags
