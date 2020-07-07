//реализирайте команда cp за произволен брой параметри
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	int fd1, fd2;
	char c;
	int read_size;
	if (argc < 3){
        err(1, "not enough arguments!");
		exit(-1);
	}
	for(int i=1; i<argc; i++) {
		fd1=open(argv[i], O_RDONLY);
		if(fd1 == -1) {
			err(1,"file couldnt open for copying");
			//exit(-1);
		}
		//we get as the resulting directory the last argument
		char* dir=malloc (strlen(argv[argc-1])+ strlen(argv[i]));
		strcpy(dir, argv[argc-1]);
		strcat(dir, "/");
		strcat(dir, argv[i]);
		printf("%s\n", dir);
		fd2 = open(dir, O_RDWR | O_CREAT, 00700);
		if(fd2 == -1) {
			err(2, "couldn't create dir for copying");
		}
		//! REMEMBER CHECKS
		while( (read_size = read(fd1, &c, 1) > 0) ) {
			if( write(fd2, &c, 1) != read_size ) {
				close(fd1);	
				close(fd2);
				//!new check, checking the read size, so we know we are still reading
				//and then if it's not writing what has been read then we exit
				err(3, "error while writing");
			}
		}
	}
	exit(0);
}
