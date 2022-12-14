#!/bin/sh

export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib

echo $1 "$1.cpp"
g++ -std=c++11 -c "$1.cpp" 
g++ -std=c++11 -o $1 "$1.o" -lsfml-graphics -lsfml-window -lsfml-system 
./$1
rm $1
rm "$1.o"
