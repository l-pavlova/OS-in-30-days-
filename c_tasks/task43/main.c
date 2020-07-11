#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "Invalid arg count!");
	}	
	//int fd = open(argv[1], O_RDONLY);
	//if(fd == -1) {
	//	err(4, "couldnt open this file");
	//}
	int a[2];
	if(pipe(a) == -1) {
		err(2, "failed to pipe");
	}
	pid_t kid = fork();
	if(kid < 0) {
		err(3, "couldnt fork");
	}
	if(kid == 0) {
		close(a[0]);
		dup2(a[1], 1);
		//close(a[0]);
		execlp("cat", "cat", argv[1], (char*)NULL);
	}
	close(a[1]);
	
	int b[2];
	if(pipe(b) == -1) {
		err(6, "couldnt pipe");
	}
	
	kid=fork();
	if(kid == -1) {
		err(5, "couldnt fork");
	}
	if(kid == 0){
		dup2(a[0], 0);
		close(b[0]);
		dup2(b[1], 1);
		execlp("sort", "sort", (char*)NULL);
	}
	close(b[1]);
	dup2(b[0],0);
	execlp("uniq", "uniq", (char*)NULL);	
	exit(0);
}
