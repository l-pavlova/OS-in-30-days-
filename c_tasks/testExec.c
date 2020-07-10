#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	//char* args[] = { "ls", "/etc/", "/bin", NULL };
	
	/*if(execlp("/bin/ls", "ls", "/etc", "/bin", (char*) NULL) == -1){
		err(11, "No such command.");
	}*/
	//execlp("ls", args)
	execlp("sleep", "gosho", "100", NULL);	
	

}
