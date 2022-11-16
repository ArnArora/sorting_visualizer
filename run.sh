#!/bin/sh

echo $1 "$1.cpp"
g++ -c "$1.cpp"
g++ -o $1 "$1.o" -lsfml-graphics -lsfml-window -lsfml-system
./$1
rm $1
