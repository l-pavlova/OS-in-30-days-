#!/bin/bash
if [ $# -ne 3 ];then
	echo Wrong arguments
	exit 1
fi
SRC=$1
DST=$2 #empty
STR=$3
if [ $(whoami) == 'grade' ];then
 	filesToMove=$(find $SRC -type f | egrep "$STR")
	if [ ! -d $DST ];then
		echo NOT A DIR
		exit 2
	else
		if [ $(find $DST -type f | wc -l) -ne 0 ]; then
			echo DIR NOT EMPTY 
			exit 3
		fi
		for file in $filesToMove; do
			file=$(basename $file)
			mv $file $DST/$file
			echo moving file $file
		done  
	fi
fi

