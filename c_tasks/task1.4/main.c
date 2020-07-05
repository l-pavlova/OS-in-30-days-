//T4 - Реализирайте команда swap, разменяща съдържанието на два файла,
// подадени като входни параметри.
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <err.h>
int main(int argc, char* argv[]) {
	if(argc != 3) {
		errx(1, "Wrong argument count!");
		exit(-1);
	}
	int fd1, fd2, fd3;
	char c;
	fd1=open(argv[1], O_RDWR );
	if(fd1 == -1) {
		err(2, "File couldnt be opened for reading or writing");
		exit(-1);
	}
	fd2=open(argv[2], O_RDWR );
	if(fd2 == -1) {
		err(3, "File couldnt be opened for reading or writing");
		exit(-1);
	}	
	fd3=open("temp.txt", O_RDWR | O_CREAT, 00700);
	if(fd2 == -1) {
		err(3, "File couldnt be opened for reading or writing");
		exit(-1);
	}
	//todo: add checks for reading
	while(read(fd1, &c, 1)) {
		write(fd3, &c, 1);
	}
	lseek(fd1, 0, SEEK_SET);
	while(read(fd2, &c, 1)) {
		write(fd1, &c, 1);
	}
	lseek(fd2, 0, SEEK_SET);
	lseek(fd3, 0, SEEK_SET);

	while(read(fd3, &c, 1)) {
		write(fd2, &c, 1);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	exit(0);
}

