#!/bin/bash
[ $# -eq 1 ] || exit 1

file=$1
pars=$(cat $file | sed "s/[^{}]//g"| tr -s "\n" " " | tr -d " " | sed "s/}{//g")
res=$((${#pars}/2))
echo The deepest nesting is $res levels

exit 0
