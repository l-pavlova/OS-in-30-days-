#include <err.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>
struct myStruct{
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
}; 
int main() {
	//so basically we make a struct, fill it up with some numbers and then write it to a file
	struct myStruct str;
	struct myStruct str1;
	str.a=7;
	str.b=6;
	str.c=4;
	str.d=3;
	str1.a=5;
	str1.b=13;
	str1.c=34;
	str1.d=11;

	int fd=open("f2", O_RDWR | O_CREAT | O_TRUNC, 0700);
	if(fd < 0) {
		err(1, "couldnt open");
	}	
	
	write(fd,&str, sizeof(str));
	write(fd, &str1, sizeof(str)); 
}
