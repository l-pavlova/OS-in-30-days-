//Koпирайте файл /etc/passwd в текущата ви работна директория и променете разделителят на копирания файл от ":", на "?"
#include <err.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {
	int fd1;
	char c;
	fd1=open("passwd", O_RDWR);
	if(fd1 == -1) {
		err(1,"couldnt open file");
		exit(-1);
	}
	while(read(fd1, &c, 1)) {
		if(c==':') {
			lseek(fd1, -1, SEEK_CUR);
			c='?';
			write(fd1, &c, 1);
		}
	}
	exit(0);
}
