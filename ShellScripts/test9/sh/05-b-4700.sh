#!/bin/bash

if [[ $# -gt 2 ]]; then
	echo too many args
	exit 10
fi
num=$1
res=0
if [[ $# -eq 2 ]];then
	delim=$2
	res="$( echo "$num" | rev | sed -r "s/(...)/\1"$delim"/g" | rev )"
else 
	res="$( echo "$num" | rev | sed -r "s/(...)/\1 /g" | rev )"
fi

echo stana li $res
