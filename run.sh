#!/bin/sh

echo $1
g++ -o $1 $1.cpp -lSFML
./$1
rm $1
