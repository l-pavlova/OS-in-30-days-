#include <unistd.h>
#include <stdio.h>
int main(void)
{
	int p1, p2;
	p1=fork();
	p2=fork();
	printf("Hello!\n");
}
