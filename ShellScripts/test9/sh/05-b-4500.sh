#!/bin/bash
[ $# -eq 1 ] || exit 1
#fix later
uid=$1
while ( true ); do 
	sleep 1
	match=$(who | grep -o $uid| cut -d " " -f1 | wc -l
)
	if [[ $match -ge 1 ]]; then 
		echo "logged"
		exit 0
	fi 	
echo going
done;



