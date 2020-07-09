#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
int comp(const void*a, const void*b) {
	if(*(char*)a>*(char*)b) {
		return 1;
	}
	return -1;
}
int main() {
	int fd=open("dump", O_RDONLY);
	struct stat st;
	stat("dump",&st);
	
	void*buff=malloc(st.st_size);
	read(fd, buff, st.st_size);
	qsort(buff, st.st_size, 1, comp);
	int fd1=open("res", O_RDWR | O_CREAT | O_TRUNC, 00700);
	write(fd1, buff, st.st_size);
   		
	exit(0);
}
