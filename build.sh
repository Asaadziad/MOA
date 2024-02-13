#!/usr/bin/bash 

mkdir -p build


# clang++  game/*.cpp -fPIC -shared -o ./build/libengine.so
clang++ main.cpp game/*.cpp math/*.cpp -o ./build/MOA -lraylib -ldl -lm -lrt -lGL -lpthread -L./build/
