#!/bin/bash
if [ $# -ne 1 ]; then
	echo wrong arg count
	exit 1
fi
NUM=$1
if [[ !($NUM == ?(-)+([0-9])) ]]; then
	echo arg is not a number
	exit 2 
fi  
if [[ $(whoami) == "grade" ]]; then
	echo we in this bitch
	USERS=$ (ps -eo user | sort | uniq)
	for user in $USERS; do
		MEMORY=$((ps -u "$user" -eo uid,pid,rss | awk '{s+=$3}END{print s}'))
		if [[ ($MEMORY == ?+([0-9])) ]]; then
			echo successfully retrieved $MEMORY 
			if [ $MEMORY -gt $NUM ]; then
				echo removing the biggest process for user $user
			fi
		fi
	done

fi
