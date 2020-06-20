#!/bin/bash

if [ ! -d "$1" ]; then
	echo not a dir
	exit 2
fi
if [ $# -ne 1 ]; then
	echo wrong arg count
	exit 1
fi
#dirname returns parent directory
find "$1" -type d | while read dir; do
		if [ $(ls "$dir" | wc -l) -gt $(ls $(dirname "$dir") |wc -l) ]; then
			echo $dir has more
		else 
			echo Parent has more
		fi
done
