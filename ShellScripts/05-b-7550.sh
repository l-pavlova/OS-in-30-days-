#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong args
	exit 1
fi
user=$1
skill -u $user
