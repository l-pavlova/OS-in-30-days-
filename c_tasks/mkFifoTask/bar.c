#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char* argv[]) {
	int fd1 = open("treva", O_RDONLY);
	dup2(fd1, 0);

	if(fork() == 0) {
		execlp("sort", "sort", (char*)NULL);
	}
	wait(NULL);
	close(fd1);
	execlp("rm", "rm", "treva", (char*)NULL);	
	

	
	exit(0);

}       
