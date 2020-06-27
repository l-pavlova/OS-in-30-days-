#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	char*buff = "Hello world!\n";
	int p;
	if(fork()==0){
	 write(1,buff,strlen(buff));
	exit(0);
	}
	p=fork();
	write(1,buff,strlen(buff));
}
