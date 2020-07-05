//Реализирайте команда cat, работеща с произволен брой подадени входни параметри.
//of nachi tva sh e mn tegavo mai mai 
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	if(argc == 1) {
		errx(1, "no files to cat");
		exit(-1);
	}
	int fd1;
	char c;
	for(int i=1; i<=argc; i++) {
		fd1=open(argv[i], O_RDONLY);
		if(fd1 == -1) {
			err(2, "couldnt display file");
			exit(-1);
		}
		while(read(fd1, &c, 1)) {	
			write(1, &c, 1);
		}
	}
	close(fd1);
	
	exit(0);
}
