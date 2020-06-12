#!/bin/bash

if [ $# -ne 2 ]; then
	echo Wrong args
	exit 1
fi
dirName=$1
size=$2
sum=0
flag=0
for entry in "$dirName"/*; do
	if [ $flag -eq 0 ]; then
		((++flag))
		continue
	fi
	curr=$(ls -1s "$entry" | cut -d " " -f1)
	if [ $curr -gt $size ]; then
		sum=$(($curr + $sum))
	fi
done
echo $sum
