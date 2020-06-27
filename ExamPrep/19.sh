#!/bin/bash
if [ $# -eq 0 ];then
	echo Wrong Args
	exit 1
elif [ $# -gt 2 ];then
	echo Wrong args
	exit 1
fi
dir=$1
if [ $# -eq 2 ]; then
	num=$2
	find $dir -type f -links +"$num"
else
	symlinks=$(ls -lR | grep ">")
	dests=$(ls -lR | grep ">" | cut -d ">" -f 2)
	for dest in $dests; do
		if [ ! -e "$dest" ]; then
			echo $symlinks| egrep $dest
		fi
	done	
fi
#a) find all files in dir recursively that have at least num hardlinks
#b) find all symlinks without real destination


