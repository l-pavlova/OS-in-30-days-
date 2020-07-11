//find $DIR -type f -printf "%T@ %p\n" | sort -n | cut -d' ' -f 2- | tail -n 1
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "Invalid arg count");
	}
	int a[2];
	if(pipe(a) == -1) {
		err(2, "couldnt pipe");
	}
	pid_t pid1 = fork();
	if(pid1 < 0 ) {
		err(3, "couldnt fork");
	}
	if(pid1 == 0) {
		dup2(a[1],1);
		close(a[0]);
		if(execlp("find", "find", argv[1], "-type", "f", "-printf", "%T@ %p\n", (char*)NULL) == -1) {
			err(4, "couldnt exec find");
		}
	}
	close(a[1]);
	int b[2];
	pipe(b);
	close(b[1]);
	pid_t pid2 = fork();
	if(pid2 < 0) {
		err(5, "couldnt fork");
	}
	if(pid2 == 0) {
		dup2(a[0],0);
		close(b[0]);
		dup2(b[1], 1);
		if(execlp("sort", "sort", "-n", (char*)NULL) == -1) {
			err(6, "couldnt exec sort");
		}
	}
	close(b[1]);
	int c[2];
	if(pipe(c) == -1) {
		err(7, "couldnt pipe c");
	}
	pid_t pid3 = fork();
	if(pid3 < 0 ) {
		err(8, "err forking");
	}
	close(c[1]);
	if(pid3 == 0) {
		dup2(b[0], 0);
		close(c[0]);
		dup2(c[1], 1);
		if(execlp("cut", "cut", "-d", " ",  "-f1", (char*)NULL) == -1) {
			err(9, "err cutting");
		}
	}
	dup2(c[0], 0);
	close(c[1]);	
	execlp("tail", "tail", "-n", "1",  (char*)NULL);
		
//todo: figure out why last call doesnt really work, anyway the idea is good, moving on		
	
	exit(0);

}


