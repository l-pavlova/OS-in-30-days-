#!/bin/bash

#shows argument count
echo $#

#checks if passed args equal 3
[ $# -eq 3 ]
echo $?

#if condition
if [ $# -eq 3 ]; then
			echo YEY
elif [ $# -eq 2 ]; then
			echo wtf
else
			echo Boo
fi

#while loop
i=0
while [ $i -lt 10 ]; do
			echo $i YEY
#aritmetic opreations are always in double paranteses
			((++i))
done

#for loop
for i in {1..5};do
		echo $i
done

for (( i=0; i < 10; ++i)); do
done

#case 
case $1 in
		2) echo TWO;;
		3) echo THREE;;
esac

