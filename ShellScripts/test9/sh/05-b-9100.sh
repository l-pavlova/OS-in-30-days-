#!/bin/bash

if [ $# -ne 2 ]; then
	echo wrong args
	exit 1
fi
src=$1
dest=$2
files=$(find $src -type f)

for file in $files; do
	dir="$dest"/"$(echo $file | cut -d '.' -f 4)"
	echo $dir
	if [ ! -d "$dir" ]; then
		mkdir "$dir"
	fi
	cp ""$src"/"$file"" "$dir"
done
