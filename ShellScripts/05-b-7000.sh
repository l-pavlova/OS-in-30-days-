#!/bin/bash

read -p "Enter string" str
while [ 1 ]; do
	echo In "$1" there are $(grep "$str" "$1" | wc -l) lines matching the string 
	shift
	if [ $# -eq 0 ]; then
		break
	fi
done

