if [ $# -ne 1 ]; then
	echo wrong args 
	exit 1
fi
i=1
while read line; do
	echo $i.$line
	i=$((i+1))
done <<< $(cat $1 | cut -d '-' -f 2,3 | sort )
