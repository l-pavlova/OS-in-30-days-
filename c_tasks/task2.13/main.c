/*Да се напише програма на C, която получава като командни параметри две команди (без параметри). Изпълнява ги едновременно и извежда на стандартния изход номера на процеса на първата завършила успешно. Ако нито една не завърши успешно извежда -1.*/
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h> 
int main(int argc, char* argv[]) {
	if(argc !=3) {
		errx(1, "wrong argument count!");
	}
	//will just run two new child ps-s and when in the child perform the cmd-s
	pid_t  pid1=fork();//some specific type for pids, a pretentious integer basically
	if(pid1 < 0) {
		err(2, "couldnt fork\n");
	}
	if(pid1== 0) {
		if(execlp(argv[1], argv[1], (char*)NULL)!=0) {
			err(3, "couldnt exec cmd: %s\n", argv[1]);
		}
		exit(0);
	}
	pid_t pid2=fork();
	if(pid2==0) {
		if(execlp(argv[2], argv[2], (char*)NULL)!=0) {
			err(4, "couldnt exec cmd: %s\n",argv[2]);
		}
		exit(0);
	}
	int status;
	pid_t wpid=wait(&status);
	int wi = wpid == pid1 ? 0 : 1;
	printf("%s finished first!\n", argv[wi+1]);
	//int firstOut;//to wait for all children to finish
	//wait(&status);
	if(WEXITSTATUS(status) != 0) {
		err(5, "Something got messed up at some point.Trace the other err messages above.\n");
	}
	
	exit(0);
}
