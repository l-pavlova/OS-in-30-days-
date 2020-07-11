#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>

struct change {
	uint16_t offset;
	uint8_t ogByte;
	uint8_t newByte;
};

int main(int argc, char* argv[]) {
	if(argc != 4) {
		errx(1, "Wrong argument count, usage <f1.bin> <f2.bin> <patch.bin>!");
	}

	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1) {
		err(2, "failed to open %s", argv[1]);
	}

	int fd2 = open(argv[2], O_RDONLY);
	if(fd2 == -1) {
		int olderr = errno;
		close(fd1);
		errno = olderr;
		err(3,  "failed to open %s", argv[2]);
	}
	
	int fd3 = open(argv[3], O_CREAT | O_RDWR | O_TRUNC, 0700);
	if(fd3 == -1) {
		int olderr = errno;
        close(fd1);
		close(fd2);
        errno = olderr;
        err(4,  "failed to open %s", argv[3]);
	}
	
 	uint8_t f;
	uint8_t s;
	uint16_t curr = 0;
	struct change ch;
	while(read(fd1,&f,sizeof(f)) == sizeof(f) && read(fd2, &s, sizeof(s)) == sizeof(s)) {
		if(f != s) {
			printf("%d %d\n", f, s);
			ch.offset = curr;
			ch.ogByte = f;
			ch.newByte = s;
			if(write(fd3, &ch, sizeof(ch)) != sizeof(ch)) {
				int olderr = errno;
		        close(fd1);
       			close(fd2);
				close(fd3);
        		errno = olderr;
				err(5, "failed to write values in %s", argv[3]);
			}

		}
		curr++;
	} 


	exit(0);
}
