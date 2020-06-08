#!/bin/bash
[ $# -eq 1 ] || exit 1
#fix later
uid=$1
while ( true ); do 
	sleep 1
	curr=$(who)
	if [[ $curr -eq $uid ]]; then 
		echo "logged"
		exit 0
	fi 	
echo going
done;



