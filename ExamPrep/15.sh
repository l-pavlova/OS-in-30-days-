#!/bin/bash
if [ $# -ne 0 ];then
	echo Wrong arument count
	exit 1
fi
if [ $(whoami) == 'root' ]; then
	#users with no home dir
	cat /etc/passwd | egrep -v 'home' | cut -d ':' -f 1
	#users that can't write in their home dir
	ALLDIRS=$(grep 'home' ../../passwd | cut -d ':' -f 1,6 )
	for dir in $ALLDIRS; do
		user=$(echo "$dir" | cut -d ':' -f1)
		currDir=$(echo "$dir" | cut -d ':' -f2)
		if ! sudo -u $user [ -r "$currDir" ]; then
			echo dir
		fi
	done


fi

