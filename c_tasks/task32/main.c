#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
struct pair {
	uint32_t f;
	uint32_t s;
};
int main() {
	int fd1 = open("f1", O_RDONLY);
	if(fd1 < 0) {
		err(1, "couldnt open");	
	}
 
	int fd2 = open("f2", O_RDONLY);
	if(fd2 == -1) {
		err(2, "couldnt open");
	}
	int fd3=open("f3", O_CREAT| O_RDWR | O_TRUNC, 0777);
	if(fd3 == -1) {
		err(3, "couldnt open");
	}

	struct pair buff;
	while(read(fd1, &buff, sizeof(buff)) == sizeof(buff)) {
		uint32_t num;
		lseek(fd2, buff.f*sizeof(uint32_t), SEEK_SET); //we set the descriptor to position the first multiplied by the size of the elements
		for(uint32_t i = 0; i< buff.s; i++) {
			if(read(fd2, &num, sizeof(num))!=sizeof(num)) {
				err(4,"Couldnt read");
			}
		 	if(write(fd3, &num, sizeof(num)) != sizeof(num)) {
				err(5, "Couldnt write");
			}
		}
	}	
	exit(0);
		 
}
