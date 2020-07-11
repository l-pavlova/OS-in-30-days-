#include <unistd.h>
#include <err.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main(void) {
	while(1) {
		if(write(1, "enter cmd", 9) != 9) {
			err(1,"couldnt create prompt");
		}
		char buff[40];
		read(0, buff, sizeof(buff));
		buff[strlen(buff) -1 ] ='\0';
		char cmd[10];
		strcpy(cmd, "/bin/");
		strcat(cmd, buff);
		if(strcmp(buff, "exit") == 0) {
			break;//exit(0);
		}
		pid_t kid=fork();
		if(kid < 0) {
			err(3, "couldnt fork");
		}
		if(kid == 0) {
			printf(cmd);
			if(execl(cmd, "cmd", (char*)NULL)== -1) {
				err(4,"couldnt exec");
			}
			//exit(0);
		}
		wait(NULL);	

	}	
	exit(0);
}

