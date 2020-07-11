#include <unistd.h>
#include <err.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

struct element {
	uint16_t offset;//start of string
	uint8_t len; 
	uint8_t res; //for the meme
};

int main(int argc, char* argv[]) {
	if(argc != 5) {
		errx(1, "Wrong argument count, usage: <file1.dat> <file1.idx> <file2.dat> <file2.idx>");
	}
	//if files are incosistent we should exit apropriately, so we go thru f1.idx and check if its in the right structus with stat
	struct stat st;
	if(stat(argv[2], &st) < 0) {
		err(44, "Failed stat");
	}
	if(st.st_size > 0xFFFF) {
		warnx("Size of %s is greater than 0xFFFF", argv[2]);
	}
	
	//we are gonna read from f1 f2.idx sized elements and copy from f1 the strings that start with a [A_Z] char
	int f1dat = open (argv[1], O_RDONLY);
	if(f1dat == -1) {
		err(2, "couldnt open file %s", argv[1]);
	}
	int f1idx = open(argv[2], O_RDONLY);
	if(f1idx == -1) {
		err(3, "couldnt open file %s", argv[2]);
	}
	int f2dat = open (argv[3], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(f2dat == -1) {
		err(4, "couldnt open file %s", argv[3]);
	}
	int f2idx = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(f2idx == -1) {
		err(5, "couldnt open file %s", argv[4]);
	}
	struct element el; //we are gonna read those from first file
	struct element y = {0,0,0}; //we are gonna write those in second
	
	uint8_t c;
	while(read(f1idx, &el, sizeof(el)) == sizeof(el)) {
				y.len = el.len;
				lseek(f1dat, el.offset, SEEK_SET);//put the descriptor to the place of the start of the string
				for(uint8_t i=0; i< el.len; i++) {
					if(read(f1dat, &c, sizeof(c)) != sizeof(c)) {
						err(6, "couldnt read from %s", argv[1]);
					}
					if(write(f2dat, &c, sizeof(c)) != sizeof(c)) {
						err(7, "couldnt write to %s", argv[3]);
					}
					
					//now the new index file
				}
				if(write(f2idx, &y, sizeof(y)) != sizeof(y)) {
					 err(8, "couldnt write to %s", argv[4]);
				}
			y.offset+=el.len;		
	}
			
	exit(0);
}
