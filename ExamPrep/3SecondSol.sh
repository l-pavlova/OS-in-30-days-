#!/bin/bash

if [ $# -ne 2 ]; then
	echo Wrong argument count
	exit 1
fi
if [ ! -d 'a' ];then
	mkdir 'a'
fi
if [ ! -d 'b' ];then
	mkdir 'b'
fi
if [ ! -d 'c' ];then
	mkdir 'c'
fi
first=$1
second=$2
while read line; do
	if [ -f $line ];then
	lcount=$(cat "$line" | wc -l)
	if [ $lcount -lt $first ]; then
			echo moving to a
			#mv file 
		elif [[ $lcount -gt $first && $lcount -lt $second ]];then
			echo moving to b
			#mv file
		else
			echo moving to c
		fi
	fi
done<<<$(ls)
