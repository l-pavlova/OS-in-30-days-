if [ $# -ne 2 ]; then
	echo wrong args 
	exit 
fi
fcount1=$(grep "$1" "$1" | wc -l)
echo $fcount1
fcount2=$(grep "$2" "$2" | wc -l)
echo $fcount2
curr=0;
if [ $fcount1 -gt $fcount2 ]; then
	curr="$1"
else 
	curr="$2"
fi
(cat $curr | cut -d "-" -f 2,3,4 | sort)>"$curr".songs


