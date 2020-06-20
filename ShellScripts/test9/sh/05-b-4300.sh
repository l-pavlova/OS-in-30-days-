#!/bin/bash
[ $# -eq 2 ] || exit 1

book=$1
user=$2
id=$(awk -F ${user} '{print $2}' $book | awk '{print $1}')
write $id

exit 0
