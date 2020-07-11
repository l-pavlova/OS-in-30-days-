#include <stdint.h>
#include <stdio.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
 #include <stdlib.h>
int comp(const void*a,const void*b) {
	if(*(uint32_t*)a > *(uint32_t*)b) {
		return 1;
	}
	return -1;
}
int main(int argc, char* argv[]) {
	if(argc !=3 ) {
		errx(1, "wromg args");
	}
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 < 0) {
		err(2, "wrong");
	} 
	int fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if(fd2 < 0) {
		err(3, "wrong");
	}
	struct stat st;	
	if(stat(argv[1], &st) < 0 ) {
		err(4, "failed stat");
	}
	int nums = st.st_size;
	 
	int temp1 = open("temp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	int temp2 = open("temp2", O_CREAT | O_RDWR | O_TRUNC, 0777);
	void*buff = malloc(nums/2);
	read(fd1, buff, nums/2);
	qsort(buff, (nums/2)/sizeof(uint32_t), sizeof(uint32_t), comp);
	write(temp1,buff, nums/2);
	free(buff);
	buff = malloc(nums - nums/2);
	read(fd1, buff, (nums- nums/2));
	qsort(buff, (nums-nums/2)/sizeof(uint32_t), sizeof(uint32_t), comp);
	
	write(temp2,buff,(nums-nums/2));
	lseek(temp1, 0, SEEK_SET);
	lseek(temp2, 0, SEEK_SET);
	uint32_t n, m;
	while(read(temp1,&n,sizeof(n)) == sizeof(n) && read(temp2, &m, sizeof(m)) == sizeof(m)) {
		if(n < m) {
			write(fd2, &n, sizeof(n));
			lseek(temp2, -1*sizeof(uint32_t), SEEK_CUR);
		} else {
			write(fd2, &m, sizeof(m));
			lseek(temp1, -1*sizeof(uint32_t), SEEK_CUR);
		}
	}
	while(read(temp1, &n, sizeof(n)) > 0 ) {
		write(fd2, &n, sizeof(n));
	}   	
	
	while(read(temp2, &m, sizeof(m)) >  0) {
		write(fd2, &m, sizeof(m));
	}   	



}
