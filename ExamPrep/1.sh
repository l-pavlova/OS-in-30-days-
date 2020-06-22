#!/bin/bash

file=$1

count=0
for line in $file; do
	if [ $(egrep '[02468]' $line) != "" ]; then
		count+=1
	fi
done
echo $count
