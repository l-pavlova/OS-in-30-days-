#!/bin/bash

if [ $# -ne 1 ];then
	echo Wrong args
	exit 1
fi
dir=$1
for entry in "$1"/*; do
	if [ -f $entry ]; then
		echo $entry of size $(ls -1sha "$entry" | cut -d " " -f1)
	else
		echo $entry contains $(ls -la $entry | wc -l) files 
	fi
done


