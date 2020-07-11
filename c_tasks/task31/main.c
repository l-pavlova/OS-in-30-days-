#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
int comp(const void*a, const void*b) {
	if(*(char*)a > *(char*)b) {
		return 1;
	}
	return -1;
}
int main() {
	int fd = open("dump", O_RDONLY);
	if(fd == -1) {
		err(1, "Failed to open file");
	}
	struct stat st;
	//use stat to get the file size basically the number count inside of it
	if(stat("dump",&st) == -1) {
		err(2, "Could not stat");
	}
	void*buff = malloc(st.st_size);
	if(read(fd, buff, st.st_size) != st.st_size) {
		err(3, "Couldnt read from file");
	}
	qsort(buff, st.st_size, 1, comp);
	int fd1 = open("res", O_RDWR | O_CREAT | O_TRUNC, 0700);
	if(fd1 == -1) {
		err(4, "Couldnt open resulting file");
	}
	if(write(fd1, buff, st.st_size) != st.st_size) {
		err(5, "Couldnt write in result");
	}
   		
	exit(0);
}
