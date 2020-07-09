/*Напишете програма, която приема точно 2 аргумента. Първият може да бъде само --min, --max или --print (вижте man 3 strcmp). Вторият аргумент е двоичен файл, в който има записани цели неотрицателни двубайтови числа */
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		err(1, "wrong arg count!");
	}
	int fd1 = open(argv[2], O_RDONLY);
	if(fd1 == -1) {
		close(fd1);
		err(2, "couldnt open for reading");
	}

	uint16_t buf;
	uint16_t min = 0xFFFF;
//	printf("the min number is iniatlly set to %d\n", min);
	uint16_t max = 0x0000;
//	printf("the max number is iniatlly set to %d\n", max);

	if(strcmp(argv[1], "--min") == 0) {
		printf("%s\n", "output smallest");
		while(read(fd1, &buf, sizeof(uint16_t)) == sizeof(uint16_t)) {
			if (min > buf) {
				min=buf;
			}
		}
		printf("%d\n", min);

	}
	else if(strcmp(argv[1], "--max") == 0) {
		printf("%s\n", "output biggest");
		while(read(fd1, &buf, sizeof(uint16_t))==sizeof(uint16_t)) {
			if(max < buf) {
				max=buf;
			}
		}
		printf("%d\n", max);			
	}
	else if (strcmp(argv[1], "--print") ==0) {
		printf("%s\n", "output all nums in lines");
		while(read(fd1, &buf, sizeof(uint16_t))==sizeof(uint16_t)) {
			printf("%d\n", buf);
		}
	}
	else { 
		printf("%s\n", "passed command was not an option");
	}
	close(fd1);	
}
