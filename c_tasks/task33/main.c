#include <unistd.h>
#include <fcntl.h>
#include <err.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
int comp(const void*a, const void*b) {
	if(*(uint32_t*)a>*(uint32_t*)b) {
		return 1;
	}
	return -1;
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "Wrong args!");
	}
	struct stat st;
	if(stat(argv[1],&st) == -1) {
		err(2, "failed to stat");
	}
	int nums = st.st_size;
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		err(3, "failed to open file for reading");
	}
	void*buff = malloc(nums/2);
	read(fd, buff, nums/2);
	qsort(buff, (nums/2)/sizeof(uint32_t), sizeof(uint32_t), comp);
	int fd1 = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0700);
	if(fd1 == -1) {
		int olderrno = errno;
		close(fd);
		free(buff);
		errno = olderrno;
		err(4, "failed to open");
	}
	if(write(fd1, buff, nums/2) != nums/2) {
		int olderrno = errno;
		close(fd);
		close(fd1);
		free(buff);
		errno = olderrno;
		err(5, "failed to write");
	}
	free(buff);
	buff=malloc(nums - nums/2);
	if(read(fd, buff, nums-nums/2) != (nums-nums/2)) {
		int olderrno = errno;
		close(fd);
		close(fd1);
		free(buff);
		errno = olderrno;
		err(6, "Failed to read");
	}
	qsort(buff, (nums-nums/2)/sizeof(uint32_t), sizeof(uint32_t), comp);
	int fd2=open("temp2", O_RDWR | O_CREAT | O_TRUNC, 0700);
	if(fd2 == -1) {
		int olderrno = errno;
		close(fd);
		close(fd1);
		free(buff);
		errno = olderrno;
		err(7, "failed to open fd2");
	}
	if(write(fd2, buff, nums-nums/2) != (nums-nums/2)) {
		err(8, "failed to write, closing everything...");
	}
	
	free(buff);
	
	int fd3=open("res", O_RDWR | O_CREAT | O_TRUNC, 0700);
	if(fd3 == -1) {
		err(9, "failed to open fd3");
	}
	//now we merge the sorted

	lseek(fd1, 0, SEEK_SET);	
	lseek(fd2, 0, SEEK_SET);
	uint32_t n, m;
	while(read(fd1,&n, sizeof(uint32_t))==sizeof(uint32_t) && read(fd2, &m, sizeof(uint32_t))==sizeof(uint32_t)) {
		if(n < m) {
			write(fd3,&n, sizeof(uint32_t));
			lseek(fd2,-1*sizeof(uint32_t), SEEK_CUR);//move the descriptor one number back bc we read it and we didnt put it anywhere 
		} else {
			write(fd3, &m, sizeof(uint32_t));
			lseek(fd1,-1*sizeof(uint32_t), SEEK_CUR);

		}
	}
	while(read(fd1,&n, sizeof(uint32_t))==sizeof(uint32_t)) {
			write(fd3,&n, sizeof(uint32_t));
	}	
	while(read(fd2,&m, sizeof(uint32_t))==sizeof(uint32_t)) {
			write(fd3,&m, sizeof(uint32_t));
	}

	exit(0);

			

		
}
