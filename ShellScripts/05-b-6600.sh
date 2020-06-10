#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong arg count
	exit 1
fi
 
dir= $1
for curr in "$dir"/*;
	 do
		echo "$curr"
		while read p;  do
			echo checking files
		done < "$(ls -l -s $dir | cut -d " " -f9)"	 
done 
