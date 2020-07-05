/*
	Реализирайте команда head без опции (т.е. винаги да извежда
	на стандартния изход само първите 10 реда от съдържанието на
	файл подаден като първи параматър)
*/
#include <err.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	printf("%d\n", argc);
	int fd1=open(argv[1], O_RDONLY);	
	if (fd1 == -1) {
		err(1, "failed to open file for reading");
		exit(-1);
	} 
	char c;
	int i=0;
	while(read(fd1, &c, 1)) {
		if(c=='\n') {
			i++;
			if(i==10) {
				write(1, &c, 1);
				break;
				close(fd1);
			}	
		}
		write(1, &c, 1);
	}
	exit(0);
}
