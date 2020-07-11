#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

struct nums {
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
};

int main() {
	struct nums n;
	n.a=1;
	n.b=2;
	n.c=12;
	n.d=4;
	struct nums m;
	m.a=2;
	m.b=34;
	m.c=14;
	m.d=234;
	int fd=open("binary", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	write(fd, &n, sizeof(n));
	write(fd, &m, sizeof(m));	
	

}
