//T2 - Да се напише програма на C, която изпълнява команда ls с точно един аргумент.
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
 	if(argc != 2) {
		err(1, "Wrong argument count!");
	}
	if(execlp("ls", "ls", argv[1], (char*)NULL) == -1) {
		err(2, "Couldn't ls %s\n", argv[1]);
	}
	exit(0);
}
