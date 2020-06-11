#!/bin/bash
if [ $# -ne 1 ]; then
	echo Wrong arg count
	exit 1
fi
 
dir= $1
for curr in "$1"/*;
	 do
		#echo "$curr"
		for currOther in "$1"/*; do
			if [[ "$curr" != "$currOther" && -f $curr && -f $currOther ]]; then
				cmp "$curr" "$currOther" 2>/dev/null
				if [ $? -eq 0 ]; then
					rm "$currOther"
					echo removing $currOther
				fi
			fi
					
		done  
done 
