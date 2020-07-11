#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
	int pipefd[2];//array containing the pipe's fd-s
	pipe(pipefd);//basically opens a new pipe with those descriptors


/*	char buff[]= "i am become death destroyer of worlds";
	write(pipefd[1], buff, sizeof(buff));
	
	here this pipe talks to itself
	char rdbuff[50];
	read(pipefd[0], rdbuff, sizeof(rdbuff));
	printf("%s\n", rdbuff);	*/
	
	/*char buff[]= "we live in a society";
	write(pipefd[1], buff, sizeof(buff));
	if(fork() == 0) {
		char rdbuff[40];
		int count = read(pipefd[0], rdbuff, sizeof(rdbuff));//here the child inherits he fds and so it can read from the same fd-s
		printf("in child, read %d bytes\n", count);
	}
	wait(NULL);
	printf("#pride month\n");*/
	
	/*close(0);	
	dup(pipefd[0]);//duplicates the passed fd with num first free fd
	execlp("sleep","sleep", "100", NULL);*/

/*	dup2(pipefd[0], 0);//duplicates the passed fd with num passed second arg fancier than dup

	execlp("sleep","sleep", "100", NULL);*/

	if(fork()==0) {
		close(pipefd[0]);
//duplicates stdout fills the pipe with the tr res		
		dup2(pipefd[1],1);
		execlp("tr","tr", "as", "@S", NULL);
	}
	close(pipefd[1]);
	if(fork() == 0) {
//waits for the pipe to be filled, then it does the second tr and writes it out
		dup2(pipefd[0], 0);
		execlp("tr", "tr", "te", "73", NULL);
	}
	int pid=wait(NULL);
	printf("%d was first\n", pid);
	
	pid = wait(NULL);
	printf("%d was second\n", pid);


	
}
