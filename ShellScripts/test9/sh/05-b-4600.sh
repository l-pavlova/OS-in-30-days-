#!/bin/bash

[ $# -eq 3 ] || exit 10

number=$1
left=$2
right=$3
if [[ ! $number =~ ^[0-9]+$ ]]; then
	exit 3
elif [ $left -gt $right ]; then
	exit 2
elif [[ $number -le $left || $number -ge $right ]]; then
	exit 1
else
	exit 0
	

fi
