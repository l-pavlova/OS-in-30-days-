//Да се напише програма на С, която получава като параметър команда (без параметри) и при успешното ѝ изпълнение, извежда на стандартния изход името на командата.
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(13, "wrong argument count!");
	}
	// so with exec we are gonna just pass the same process to the command given
	//so we need to fork first, perform the command, then do the do
	int pid=fork();
	int res;
	if(pid==0) {

		if(execlp(argv[1], argv[1], (char*)NULL) == -1) {
			err(1, "couldn't find command lol");
		}
	}
	else{
		wait(&res);
		if(WIFEXITED(res)) {	
			printf("Successfully executed %s\n", argv[1]);
		}
	}
	exit(0);
}
