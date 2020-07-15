#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char* argv[]) {
	
   	int p = mkfifo("treva",0777);
	
	int fd = open("treva", O_WRONLY);
	
	dup2(fd, 1);
	if(fork() == 0 ) {
		execlp("cat", "cat", argv[1], (char*)NULL);
	}
	wait(NULL);
	close(fd);
		
	

	exit(0);
}
