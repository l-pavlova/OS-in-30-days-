#!/bin/bash

if [ $# -ne 0 ]; then
	echo Wrong args
fi
result=0;
directories=$(echo $PATH | tr -s ':' '\n')
for line in $directories; do
	result=$((result+$(find $line -executable -type f | wc -l)))
done
echo $result

