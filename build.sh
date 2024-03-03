#!/usr/bin/bash 

mkdir -p build


# clang++  game/*.cpp -o ./MOA
clang++ engine/*.cpp -o ./build/MOA -lraylib -ldl -lm -lrt -lGL -lpthread
