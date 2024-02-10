#!/usr/bin/bash 

set echo on

mkdir -p ../bin

cFilenames=$(find . -type f -name "*.cpp")

assembly="app"
compilerFlags=""

includeFlags="-Isrc"
linkedFlags=""
defines=""

echo "Building $assembly..."
clang++ $cFilenames $compilerFlags -o ../bin/$assembly $defines $includeFlags $linkedFlags
