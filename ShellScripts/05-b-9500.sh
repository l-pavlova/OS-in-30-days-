#!/bin/bash

if [ $# -ne 2 ]; then
	echo Wrong arg count
	exit 1
fi
color=$1
str=$2
case $color in
	-r)
		 echo -e "\\033[0;31m $str";;
	-g) 
		echo  -e "\\033[0;32m $str";;
	-b)
		echo -e "\\033[0;34m $str";;
	*)
		echo no such color 
		exit 2;;
esac
echo -e '\033[0m'

