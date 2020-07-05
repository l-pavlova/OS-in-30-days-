//T3 - Реализирайте команда wc, с един аргумент подаден като входен параметър
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
	if(argc != 2) {
		errx(1, "wrong arg count!");
		exit(-1);
	}
	int fd1;
	char c;
	fd1=open(argv[1], O_RDONLY);
	if(fd1 == -1) {
		err(2, "couldnt open file for reading");
		exit(-1);
	}	
	printf("%s\n", "we in");
	u_int32_t words=0;
	while(read(fd1, &c, 1)) {
		if(c==' ' || c=='\n' || c=='\t' || c=='-') {
			words++;
		}
	}
	//printf("%s\n", "next we print the words hopefully");
	//write(1, &words, sizeof(words));
	printf("%d\n", words);
	
	close(fd1);
	exit(0);

}
