#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char*argv[]) {

	if(argc < 2) {
		errx(1, "no args passed to cmd");
	}
	uint32_t linenum = 1;
	bool flag = false, another = false;
	int fd;
	setbuf(stdout, NULL);// with this it prints once the printf, once the write and its
	// all good , otherwise it prints the lines and then 1 2 3  4...

	for(int i = 1; i < argc; i++) {
		if((strcmp(argv[i], "-n") == 0) && i==1) {
			flag = true;
			another = true;
			i++;
		}
		if(strcmp(argv[i],"-") == 0) {
			//read from stdin
			fd = 0;
		} else { 
			fd = open(argv[i], O_RDONLY);
		}

		char c;
		while(read(fd, &c, sizeof(c)) > 0) {
			if(another) {
				printf("%d ", linenum++);
				another = false; //print the line for the first line
			}
			write(1,&c, 1); 			 
			if(flag) {
				if(c=='\n') {
					printf("%d ", linenum++);
				} //todo: fix printing linenum on last line	
			}
		}
	}
	exit(0);		

}
