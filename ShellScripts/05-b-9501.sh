#!/bin/bash

if [ $# -ne 1 ]; then
		echo Wrong args
		exit 1
fi

color=$1
while [ true ]; do
	read -p "enter input" input 
	case $color in
    -r)
		read -p "enter input" str 
        echo -e "\\033[0;31m $str"
		read -p "enter input" input 
        echo -e "\\033[0;32m $str"
		read -p "enter input" input 
        echo -e "\\033[0;34m $str";;
	-g) 
		read -p "enter input" str 
        echo  -e "\\033[0;32m $str"
		 read -p "enter input" input 
        echo  -e "\\033[0;34m $str"
		 read -p "enter input" input 
        echo  -e "\\033[0;31m $str";;
    -b)
		read str
        echo -e "\\033[0;34m $str"
		read -p "enter input" input 
        echo  -e "\\033[0;31m $str"
		read -p "enter input" input 
        echo  -e "\\033[0;32m $str";;


    *)
        echo no such color 
        exit 2;;
esac
echo -e '\033[0m'
done 
