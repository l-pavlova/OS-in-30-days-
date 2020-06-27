#!/bin/bash
if [ $# -ne 3 ]; then
	echo Wrong argument count
	exit 1
fi
fileName=$1
if [ ! -f $1 ]; then
	echo Argument not a file
	exit 2
fi
str1=$2
str2=$3
values1=$(cat "$fileName" | grep "$str1" | cut -d "=" -f 2)
values2=$(cat "$fileName" | grep "$str2" | cut -d "=" -f 2)
for term in $values1; do
	if [[ " ${values2[@]} " =~ $term ]];then
		echo $term is in second, remove it
		oldLine=$values2
		values2=$(echo $values2 | tr $term " ")
		 sed -i s/"$oldLine"/"$values2"/g $fileName
	fi
done
#go thru the sth
#rm those from vals2
echo $values1
echo $values2
cat $fileName

