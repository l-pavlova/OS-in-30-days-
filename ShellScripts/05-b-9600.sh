#!/bin/bash
back="~/BACKUP_DIR"
if [ ! -d "~/BACKUP_DIR" ]; then
	#mkdir "~/BACKUP_DIR"
	export back	
fi
while [ 1 ]; do
	if [ $1 == "-r" ]; then
		shift
		if [ -d $1 ]; then
			dir=$(dirname $1)
            echo deleting empty $dir and comressing
            tar -cJf $dir.tar.gz $dir
            mv $dir.tar.gz "../BACKUP_DIR/"$dir.tar.gz
            rm -r $dir
		fi
	fi
	if [ -f $1 ]; then
		echo deleteting a file and compressing
		file=$(basename "$1")
		file+=_"$(date +'%d%m%y')"
		echo $file
		echo compressing $1
		tar -czvf "$file.tar.xz" "$1"
		mv $file.tar.gz "../BACKUP_DIR"/$file.tar.gz
		rm $1
	fi
	if [ -d $1 ]; then
		if [ $(ls -l $1 | wc -l) -eq 1 ]; then
			dir=$(dirname $1)
			echo deleting empty $dir and comressing
			tar -cJf $dir.tar.gz $dir 
			mv $dir.tar.gz "../BACKUP_DIR"/$dir.tar.gz
			rmdir $dir
		fi
	fi
	shift
	if [ $# -eq 0 ]; then
		break
	fi
done
