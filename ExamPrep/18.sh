#!/bin/bash 

recent=$(find ~ -type f -printf '%T@ %p\n' | sort -t " " -k 1 | tail -n 1 | cut -d " " -f 2)
echo removing $recent
rm $recent
