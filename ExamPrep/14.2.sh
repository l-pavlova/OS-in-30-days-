#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong arg count
	exit 1
fi
if [[ ! $1 =~ [0-9] ]]; then
	echo not a num
	exit 2
fi
NUM=$1
if [[ $(whoami) == 'root' ]];then
	USERS=$(cut -d : -f 1 /etc/passwd)
	for user in $USERS; do
		ALL=$(ps -u $user -e -o uid,pid,rss | awk 'BEGIN{s=0}{s=s+$3}END{print s}')
	if [ $ALL -gt $NUM ]; then
		PIDTOKILL=$(ps -eo pid,rss | grep $(ps -u grade -e -o rss | sort -nr |head -n 1) | awk '{print $1}')
		echo Killing process with PID $PIDTOKILL
		#kill $PIDTOKILL
	fi	
	done
fi 

		
