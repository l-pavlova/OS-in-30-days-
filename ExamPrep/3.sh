if [ $# -ne 2 ]; then
	echo wrong params
	exit 1
fi
if [ ! -d 'a' ]; then
	mkdir 'a';
fi
if [ ! -d 'b' ]; then
	mkdir 'b'
fi
if [ ! -d 'c' ]; then
	mkdir 'c'
fi

while read line; do
	if [ -f "$line" ]; then
		lcount=$(cat "$line" | wc -l)
		if [ $lcount -lt $1 ]; then
			echo moving to a
			#mv "$line" ./a/$line
		elif [[ $lcount -gt $1 && $lcount -lt $2 ]];then
			echo moving $line to b
		else
			echo moving $line to c
		fi 
	fi
done<<<$(ls) 


