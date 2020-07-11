#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
int comp(const void*a, const void*b) {
	if(*(uint32_t*)a>*(uint32_t*)b) {
		return 1;
	}
	return -1;
}

int main(){ 
	int a=2;
	int b=12;
	int res = comp(&a, &b);
	printf("res is %d:", res);
}
