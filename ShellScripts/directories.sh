#!/bin/bash

#vurvim po vs direktorii
if [ $# -ne 1 ]; then
		echo Wrong args
		exit 1
fi
if [ ! -d "$1" ]; then
			echo Not a directory
			exit 2
fi

#вървим по директориите
find "$1" -type d | while read dir; do
#vzimame vs direktorii
			dirCount= $(ls "dir" | wc -l)
#dirname vzima parent direktorii na tekushtata
			parCount=$(ls $(dirname "dir") |wc -l)
#ako e greater nachi printim 
			if [ $"dirCount" -gt $"parCount" ]; then
				echo $dir has more
			else 
				echo Parent has more
			fi
			
			echo $dir has $dirCount , parent has $parCount
done


