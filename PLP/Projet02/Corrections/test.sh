#!/bin/bash
gcc -o snake snake.c -lm -Wall -std=c99 &> compil.txt
echo "./snake" > test1.txt
./snake 1>> test1.txt 2>> test1.txt
echo "./snake 10x10" > test2.txt
./snake 10x10 1>> test2.txt 2>> test2.txt
echo "./snake 10x10 3" > test3.txt
./snake 10x10 3 1>> test3.txt 2>> test3.txt
echo "./snake 10x10 3 0" > test4.txt
./snake 10x10 3 0 1>> test4.txt 2>> test4.txt
echo "./snake 10x20 1 0" > test5.txt
./snake 10x20 1 0 1>> test5.txt 2>> test5.txt
echo "./snake 1x1 1 0" > test6.txt
./snake 1x1 1 0 1>> test6.txt 2>> test6.txt
echo "./snake 3x3 1 0" > test7.txt
./snake 3x3 1 0 1>> test7.txt 2>> test7.txt
