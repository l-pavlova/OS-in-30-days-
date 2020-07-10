/*Да се напише програма на C, която изпълнява последователно подадените ѝ като параметри команди, като реализира следната функционалност постъпково:
main cmd1 ... cmdN Изпълнява всяка от командите в отделен дъщерен процес.
... при което се запазва броя на изпълнените команди, които са дали грешка и броя на завършилите успешно.*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int succ=0;
	int status;
	int fail=0;
	for(int i=1; i<argc; i++) {
		int pid=fork();
		if(pid==0) {
			if(execlp(argv[i], argv[i], (char*)NULL) !=0) {
				exit(1);
			} 
		}
		wait(&status);
		if(WIFEXITED(status)) {
			if(WEXITSTATUS(status)!=0){
				fail++;
			} else {
				succ++;
			}
		}
	}
	printf("SUCC: %d, FAIL: %d\n", succ, fail);

	exit(0);
}
