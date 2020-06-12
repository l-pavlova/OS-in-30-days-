#!/bin/bash
if [ $# -ne 0 ]; then
	echo Wrong arg count
	exit 1
fi
number=$(((RANDOM %10)))
#echo Number to guess $number
count=1
while [ 1 ]; do
	read -p "Guess " num
	case $num in ''|*[!0-9]*)
		echo error: not a number 
		exit 2;;
	esac
	if [[ $num -eq $number ]]; then
		echo You guessed in $count tries!
		break
	elif [[ $num -lt $number ]]; then
		echo Try bigger!
	else 
		echo Try smaller!
	fi
	((++count))

done
