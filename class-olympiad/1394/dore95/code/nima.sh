#!/bin/bash
flag=0;
g++ -o naive.out naive.cpp
g++ -o code.out code.cpp
while [ $flag = 0 ]; do
	./gen.out > outgen
	./naive.out < outgen > inpnaive
	./code.out < outgen > inpcode
	res=$(diff -q inpcode inpnaive)
	if [ "$res" != "" ]; then
		flag=1
	fi
done
