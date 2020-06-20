#!/bin/bash

if [ $# -nt 1 ]; then
	echo "Wrong argument count"
	exit 3
fi
#double parantesis allow advanced test features such as testing if a string matches a regex

if [[ $1 =~ ^[a-zA-Z0-9]+$ ]] ; then
	echo "Contains only letters and digits!"
else 
	echo "Contains other characters!"
fi
exit 0


