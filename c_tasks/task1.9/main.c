#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		err(1, "wrong arg count!");
	}
	int fd1;
	char c;
	if(strcmp(argv[1], "--min") == 0) {
		printf("%s\n", "output smallest");
	}
	else if(strcmp(argv[1], "--max") == 0) {
		printf("%s\n", "output biggest");
	}
	else if (strcmp(argv[1], "--print") ==0) {
		printf("%s\n", "output all nums in lines");
	}
	else { 
		printf("%s\n", "passed command was not an option");
	}
	fd1=open(argv[2], O_RDONLY);
	if(fd1 == -1) {
		err(2, "couldnt open for reading");
	}
	//halp.
}
