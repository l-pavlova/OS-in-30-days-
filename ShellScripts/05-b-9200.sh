#!/bin/bash

while [ 1 ]; do
 	echo $1
	if [ -f $1 ]; then
		echo removed file "$1" at $(date)>>log.txt
		rm "$1" 
	fi
	if [ -d "$1" ]; then
		if [ $(ls -l $i | wc -l) -eq 1 ]; then
			rmdir "$1"
			echo removed empty dir "$1" at $(date)>>log.txt
		fi
	fi
	shift
	if [ $# -eq 0 ]; then
		break
	fi
done
