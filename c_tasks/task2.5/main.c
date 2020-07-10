// Да се напише програма на C, която е аналогична на горния пример, но принуждава бащата да изчака сина си да завърши.//yeees okay, now i see the point, we shall fork again
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pid=fork();
	if(pid == -1) {
		err(1, "couldn't fork");
	}
	int buff;
	wait(&buff);
	if(WIFEXITED(buff)) {
		if(pid >0) {
			printf("Child is done.\n");
		}
	}
	//basically when we do the wait, it's gonna do the thin after the kid is done
	exit(0);
}
