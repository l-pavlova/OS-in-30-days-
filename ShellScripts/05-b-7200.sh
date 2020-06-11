#!/bin/bash

while [ 1 ]; do
	echo "$1"
	if [ -f "$1" ]; then
		echo "$1" is a file
	elif [ -d "$1" ]; then
		echo "$1" is a directory with files:
		cntFiles=$(ls -l "$1" | wc -l)
			for entry in "$1"/*; do
				if [[ $(ls -s "$entry" | cut -d " " -f1) -gt "$cntFiles" ]]; then
					echo $entry
				fi
			done
	fi
	shift
	if [ $# -eq 0 ]; then
		break
	fi
done
