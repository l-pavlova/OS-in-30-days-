//Да се напише програма на C, която създава процес дете и демонстрира принцина на конкурентност при процесите. (eeeeh? just gonna fork)
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <stdio.h>
int main() {

	int pid = fork();
	if(pid == -1) {
		err(1, "couldnt fork!");
	}
	if(pid == 0) {
		printf("We are in the child rn\n");
		printf("We are in the child rn\n");

	}
	else {
		printf("we in the parent\n");
		printf("we in the parent\n");

	}
	exit(0);
}



