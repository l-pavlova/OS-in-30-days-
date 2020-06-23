#!/bin/bash
if [ $# -ne 1 ]; then
	echo wrong args
	exit 1
fi
dir=$1
if [[ -f $1 ]]; then
	echo not a dir
	exit 2
fi
#find all symlinks
#find the nonexistent dest wit if -e 
links=$(ls -lR $dir| egrep ">")
for curr in $links; do
	dest=$(echo $curr | cut -d ">" -f 2 )
	if [ -e $dest ]; then
		echo $curr
	fi
done

