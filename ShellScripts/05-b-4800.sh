#!/bin/bash

if [ $# -ne 2 ]; then
	echo Incorrect arg count
	exit 1
fi
if [ ! -d "$2" ]; then
		echo not a dir
		exit 2 
fi
file=$1
dir=$2
#get all files in the dir
for entry in "$dir"/*;	do 
		status="$(diff -s "$entry" "$file" 2>/dev/null)"
		if [[ $status -eq 0 ]]; then
			echo match
			exit 0
		fi
done
echo no match

