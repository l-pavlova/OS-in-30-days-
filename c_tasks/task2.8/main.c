//Да се напише програма на С, която получава като параметър име на файл. Създава процес син, който записва стринга foobar във файла (ако не съществува, го създава, в противен случай го занулява), след което процеса родител прочита записаното във файла съдържание и го извежда на стандартния изход, добавяйки по един интервал между всеки два символа.
#include <err.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "wrong argument count!");
	}
	int pid=fork();
	int fd;
	int status;

	if(pid == 0) {
		char*buff=malloc(strlen("foobar"));
		strcpy(buff, "foobar");
		if((fd=open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 00700)) == -1) {
			err(2, "Couldnt open file");
		}
		if(write(fd, buff, sizeof(buff)) != sizeof(buff)) {
			err(3, "Couldnt write in file");
		}
	}
	if(pid > 0) {
		wait(&status);
		lseek(fd, 0, SEEK_SET);
		if((fd=open(argv[1], O_RDONLY)) == -1) {
			err(4, "couldnt open file to print");
		}
		char c;
		int i=0;
		uint8_t readsize;
		while( (readsize = read(fd, &c, 1) ) > 0) {
			if( write(1, &c, 1) != readsize) {
				close(fd);
				err(5, "error while writing");
			}
			i++; 	
			if( i%2 == 0) {
				if(write(1, " ", 1) < 0) {
					err(6, "error while writing");
				}
			}
 		}
		close(fd);
		//free(buff);
	}		
	exit(0);
}
