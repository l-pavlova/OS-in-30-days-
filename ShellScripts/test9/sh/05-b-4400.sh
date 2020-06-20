#!/bin/bash

[ $# -eq 2 ] || exit 1
currDir=$1
dest=$2
files=$(find $1 -mmin -45)
for file in $files; do
	cp $currDir/$file $dest/
	echo copying
done 
exit 0
 

