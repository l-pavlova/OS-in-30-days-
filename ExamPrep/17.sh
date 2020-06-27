#!/bin/bash

if [ $# -ne 1 ]; then
	echo Wrong argument count
	exit 1
fi
usr=$1
if [[ $(whoami) == 'grade' ]]; then
	procCount=$(ps -u $usr | wc -l)
	echo Processes for user are $procCount	
	usrs=$(ps -e u | cut -d ' ' -f1 | sort |uniq)
	for u in $usrs; do	
		currPC=$(ps -u $u 2>/dev/null | wc -l)
		if [ $currPC -gt $procCount ]; then
			echo $u has more proccesses
		fi
	done
	#b) avg work time for processes for all users
	avg=$(ps -eo pid,time| cut -d ":" -f 3 | awk 'BEGIN{s=0;cnt=0}{s+=$1; cnt++}END{print s/cnt}') 
	echo Proccesses wrok on average for $avg seconds
	#c) kill processes of user that have worked twice the average
	userProcs=$(ps -u $usr -eo pid,time)
	for pr in $userProcs; do
		workTime=$(echo $pr | cut -d ":" -f 3 | sed 's/0//g')
		#if (( $(echo "$workTime > $avg " | bc -l) )); then
		#	echo kill!		
	#echo $(echo $pr | cut -d " " -f 1) worked too long, killing it
			#kill pid
		#fi this would work if there was bc on the machine
	done
	#echo $userProcs
		
fi
