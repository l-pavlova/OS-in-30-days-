#include <err.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "Wrong argument count!");
	}
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1) {
		close(fd1);
		err(2, "File couldnt open for reading!");
	}
	uint8_t buf; 
	uint8_t byte = 000;
	printf("Byte is initially %d\n",byte);
	while(read(fd1, &buf, sizeof(uint8_t)) == sizeof(buf)) {
		if(byte < buf) {
			byte=buf;
		}	
	}
	printf("result is %d\n", byte);
	exit(0);
}
