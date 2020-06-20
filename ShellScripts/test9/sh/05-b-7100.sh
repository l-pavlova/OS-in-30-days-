#!/bin/bash

if [ $# -ne 2 ]; then
	echo Wrong arg count
	exit 1
fi
dirName=$1
number=$2
for entry in "$dirName"/*; do
	if [[ $(ls -1s $entry | cut -d " " -f1) -ge $number && -f $entry ]]; then

		echo  $entry  
	fi
done

	
