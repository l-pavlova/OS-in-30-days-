//Да се напише програма на С, която получава като параметри три команди (без параметри), изпълнява ги последователно, като изчаква края на всяка и извежда на стандартния изход номера на завършилия процес, както и неговия код на завършване.
#include <err.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {

	if(argc != 4) {
		errx(1, "wrong arg count");
	}
	for(int i=1; i<argc; i++) {
		int pid1=fork();
		if(pid1 == -1) {
			err(2, "couldnt fork");
		}
		int status;
		if(pid1 == 0) {
			printf("in child\n");
			if(execlp(argv[i], argv[i], (char*)NULL) == -1) {
				err(3, "Couldnt exec %s\n", argv[1]);
			}
		}
		wait(&status);
		if(WIFEXITED(status)) {
			printf("Process with pid: %d\t ended with code %d\n", pid1, WEXITSTATUS(status));
		}

	}
	
	exit(0);
}
