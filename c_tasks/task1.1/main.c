//Реализирайте команда cp, работеща с два аргумента, подадени като входни параметри.
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>
int main(int argc, char* argv[]){
	//argv[0] returns main.c
	//argc returns arg count +name
	if(argc!=3){
		errx(1,"failed to read ars");//errx for user error
	}
	int fd0=open(argv[1], O_RDONLY);
	 //add checks
	//
    int fd1=open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	char c;
	while(read(fd0, &c, 1)) {
		write(fd1, &c, 1);
	}
	exit(0);


}
