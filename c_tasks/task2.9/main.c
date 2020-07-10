//Да се напише програма на C, която която създава файл в текущата директория и генерира два процесa, които записват низовете foo и bar в създадения файл.
//Програмата не гарантира последователното записване на низове.
//Променете програмата така, че да записва низовете последователно, като първия е foo.
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
	int fd=open("res", O_RDWR | O_TRUNC | O_CREAT, 00700);
	if(fd == -1) {
		err(1, "Couldnt open file for writing");
	}
	int pid=fork();
	if(pid < 0) {
		close(fd);
		err(12,"couldnt create process");
	}
	if(pid==0){
		if(write(fd, "foo", 3) < 0){
			close(fd);
			err(2, "couldnt write foo lol");
		}
	}
	if(pid > 0) {
	int status;
	wait(&status);
	int pid2=fork();
	if(pid2 < 0) {
			close(fd);
			err(13,"couldnt create process");
	}
	if(pid2==0) {
			if(write(fd, "bar", 3) < 0) {
				close(fd);
				err(3, "couldnt write bar :(");
			}
		}
	}
	exit(0);
}
