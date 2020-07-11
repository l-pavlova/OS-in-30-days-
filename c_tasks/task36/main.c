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
	uint32_t linenum=1;
	bool flag=false, another=true;
	if(strcmp("-n", argv[1])==0) {
		flag=true;
	}
	int fd;
	setbuf(stdout, NULL);
	for(int i=2; i<argc; i++) {
		if(strcmp(argv[i],"-")==0) {
			//read from stdin
			fd = 0;
		} else { 
			fd = open(argv[i], O_RDONLY);
		}
		char c;
		
		while(read(fd, &c, 1) > 0) {
		if(another) {
					printf("%d ", linenum++);
					another=false;
				}
		write(1,&c, 1); 
		if(flag) {
				
				if(c=='\n') {
					printf("%d ", linenum);
					linenum++;
				}
				
			}
		}
	}
		

}
