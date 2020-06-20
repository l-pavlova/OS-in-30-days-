#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong arg count
	exit 1
fi
user=$1
memories=$(ps -o pid,rss,vsz -u $user|tr -s "  " " "|awk -F ' ' '{printf " %.2f", $2/$3}'
)
curr=0
for line in $memories; do
	echo $line
done



