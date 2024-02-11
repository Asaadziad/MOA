#!/usr/bin/bash 

mkdir -p build


clang++ engine.cpp -fPIC -shared -o ./build/libengine.so
clang++ main.cpp -o ./build/MOA -lraylib -ldl -lm -lrt -lGL -lpthread -L./build/
