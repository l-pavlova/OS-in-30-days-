#!/bin/bash
if [ $# -nt 4 ];then
	echo "boo"
	exit 4
fi
#paste -s writes the two files one after another
paste -s $1 $2>temp>sort >>$3
rm temp
exit 0
