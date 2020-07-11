//cat passwd | cut -d : -f 7 | sort |uniq -c | sort -n
#include <err.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	int a[2];
	if(pipe(a) == -1) {
		err(1,"couldnt pipe");
	}
	pid_t kid = fork();
	if(kid < 0) {
		err(2, "couldnt fork");
	}
	if(kid == 0) {
		dup2(a[1],1);
		close(a[0]);
		if(execlp("cat", "cat", "passwd", (char*)NULL) == -1) {
			err(3, "couldnt cat");
		}
		
	}
	close(a[1]);
	int b[2];
	if(pipe(b) == -1) {
		err(4, "couldnt pipe");
	}
	pid_t pid = fork();
	if(pid < 0) {
		err(5, "couldnt fork");
	}
	if(pid == 0) {
		dup2(a[0], 0);
		close(b[0]);
		dup2(b[1], 1);
		if(execlp("cut", "cut", "-d", ":", "-f7", (char*)NULL) == -1) {
			err(6,"couldnt exec cut");
		}	
	}
	close(b[1]);
	int c[2];
	pipe(c);
	pid_t pid2=fork();
	if(pid2 < 0) {
		err(7, "couldnt fork");
	}
	if(pid2 ==0) {
		dup2(b[0], 0);
		close(c[0]);
		dup2(c[1],1);
		execlp("sort", "sort", (char*)NULL);	
	}
	close(c[1]);
	int d[2];//haha d2
	pipe(d);
	pid_t pid3 = fork();
	if(pid3 < 0) {
		err(8, "couldnt fork");
	}
	if(pid3 == 0) {
		dup2(c[0], 0);
		close(d[0]);
		dup2(d[1],1);
		execlp("uniq", "uniq", "-c", (char*)NULL);
	}
	close(d[1]);
	dup2(d[0], 0);	
	execlp("sort", "sort" , "-n", (char*)NULL);
	exit(0);
}
