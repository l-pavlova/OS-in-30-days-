#!/bin/bash
if [ $# -ne 0 ];then
	echo wrong arg count
fi
cmp() {
	awk -v n1="$1" -v n2="$2" 'BEGIN {printf "%s " (n1<n2?"<:">=") " %s\n", n1,n2'
}
if [[ $(whoami) == 'grade' ]]; then
	users=$(ps -e u | cut -d ' ' -f 1 | sort | uniq)
		for user in $users; do
			currMem=$(ps -u $user -eo pid,rss 2>/dev/null | awk 'BEGIN{s=0;cnt=0}{s+=$2;cnt++}END{print $1 s/cnt}')
			echo Average for $user is $currMem
			max=$(ps -u grade -eo rss,pid | sort -nr | head -n 1)
			max=$max*2
			#res="$(cmp $currMem $max)"
			echo result is $res
			#if its bigger we kill it
		done
fi
