#!/bin/sh

export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib

echo $1 "$1.cpp"
g++ -c "$1.cpp" -v 
g++ -o $1 "$1.o" -lsfml-graphics -lsfml-window -lsfml-system -v
./$1
rm $1
rm "$1.o"
