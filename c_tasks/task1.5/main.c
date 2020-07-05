//Реализирайте команда cp, работеща с два аргумента, подадени като входни параметри.
#include <sys/types.h>
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char* argv[]) {
	if(argc != 3 ) {
		errx(1, "Wrong argument count!");
		exit(-1);
	}
	int fd1, fd2;
	char c;
	fd1=open(argv[1], O_RDONLY);
	if(fd1 == -1) {
		err(2, "Couldn't open to copy");
		exit(-1);
	}
	fd2=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if(fd2 == -1) {
		err(3, "Couldnt open new file to copy into");
		exit(-1);
	}
	while(read(fd1, &c, 1)) {
		write(fd2, &c, 1);
	};
	close(fd1);
	close(fd2);
	exit(0);
}
