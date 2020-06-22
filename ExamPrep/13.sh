#!/bin/bash
if [ $# -ne 1 ]; then
	echo wrong args
	exit 1
fi
dir=$1
if [[ -f $1 ]]; then
	echo not a dir
	exit 2
fi
