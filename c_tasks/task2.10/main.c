//Да се напише програма на C, която получава като параметри от команден ред две команди (без параметри). Изпълнява първата. Ако тя е завършила успешно изпълнява втората. Ако не, завършва с код 42.
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
	if(argc != 3) {
		errx(1, "Wrong argument count!");
	}
	int pid=fork();
	int status;
	if(pid == 0) {
		execlp(argv[1], argv[1], (char*)NULL);
	}
	wait(&status);
	//todo:fix!!
	if(status!=0) {
		exit(42);
	}
	if(WIFEXITED(status)) {
		printf("exit status is : %d\n", status);
		if(WEXITSTATUS(status) == 0) {
			if(pid > 0) {
				execlp(argv[2], argv[2], (char*)NULL);
			}
		}
		else if(WEXITSTATUS(status) != 0) {
			exit(42);
		}
	}
//	exit(0);
}
