#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong arg count
	exit 1
fi
user=$1
memories=$(ps -o rss,vsz -u "$user" | sort -n -r | head -n -1)
curr=0;
awk -F ' ' '{printf ""$3" %.2f\n, $1/$2}'
 

