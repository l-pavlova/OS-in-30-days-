#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

struct change {
	uint16_t offset;
	uint8_t ogByte;
	uint8_t newByte;
};

int main(int argc, char* argv[]) {
	if(argc != 4) {
		errx(1, "Wrong arguments, enter patch.bin, f1.bin, f2.bin!");
	}
	
	struct stat st;
	if(stat(argv[1], &st) < 0) {
		err(34, "Failed stat");
	}
	if(st.st_size % sizeof(struct change) != 0) {
		errx(43, "Invalid size of file %s", argv[1]);
	}
	if(stat(argv[2], &st) < 0) {
		err(23, "Failed stat");
	}
	if(st.st_size > 0xFFFF) {
		warnx("Size of %s is greater than 0xFFFF", argv[2]);
	}
	
	int fpatch = open(argv[1], O_RDONLY);
	if(fpatch == -1) {
		err(2, "couldnt open %s", argv[1]);
	}
	
	int ff1 = open(argv[2], O_RDONLY);
 	if(ff1 == -1) {
		int olderrno = errno;
		close(fpatch);
		errno = olderrno;
        err(3, "couldnt open %s", argv[2]);
    }	
	
	int ff2 = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(ff2 == -1) {
        int olderrno = errno;
        close(fpatch);
        close(ff1);
		errno = olderrno;
        err(4, "couldnt open %s", argv[3]);
    }
	
	//first copy 1:1 the file 	
	uint8_t c;
	while(read(ff1, &c, sizeof(c)) == sizeof(c)) {
		if(write(ff2, &c, sizeof(c)) != sizeof(c)) {
			int olderrno = errno;
        	close(fpatch);
        	close(ff1);
			close(ff2);
        	errno = olderrno;
			err(5, "couldnt write in new file");
		}
	}
	
	//then read the patch and replace the changed
	lseek(ff1, 0, SEEK_SET);
	lseek(ff2, 0, SEEK_SET);
	struct change ch;
	uint8_t repl;
	while(read(fpatch, &ch, sizeof(ch)) == sizeof(ch)) {
	
		lseek(ff2, ch.offset, SEEK_SET);
		repl = ch.newByte;
		if(write(ff2,&repl, sizeof(repl)) != sizeof(repl)) {
			int olderrno = errno;
			close(fpatch);
		 	close(ff1);
			close(ff2);
			errno = olderrno;
			err(7, "couldnt write diff");
		}
	}											  
	
	
	exit(0);
}
