#!/bin/bash
[ $# -eq 3 ] || exit 1
book=$1;
fullName=$2;
nick=$3;
#here the actual task conditions were unclear so this how we roll
name=$(cat /etc/passwd |grep $fullName| cut -d ":" -f1)
echo $nick $name>>$book
exit 0
