#include <unistd.h>
#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
int main(int argc, char* argv[]) {
	
	if(argc < 2 || argc > 6) {
		errx(1, "Wrong arguments!");
	}
	if(strcmp(argv[1], "-c") == 0) {
		if(strlen(argv[2]) == 1) {
			//printf("in chars lol");
			int n = *argv[2] - '0';
			char c;
			for(uint8_t i = 0; i< n; i++) {
				read(0, &c, 1);
			}
			write(1, &c, 1);
					
		} else if(strlen(argv[2]) == 3) {
			int n1 = *argv[2] - '0';
			int n2 = *(argv[2]+2) - '0';
			char c;
			for(uint8_t i=0; i< n1; i++) {
				read(0, &c, 1);
			}
			for(uint8_t i=n1; i<=n2;i++) {
				read(0, &c, 1);
				write(1, &c, 1);
			}
		}
	}
	if(strcmp(argv[1], "-d") == 0 && strcmp(argv[3], "-f") == 0 ) {
		char d = *argv[2];
		if(strlen(argv[4]) == 1) {
			int n = *argv[4] - '0';
			char curr;
			int i=1;
			while(i < n) {
				while(read(0,&curr,1) > 0) {;
					if(d ==  curr) {
						i++;
					}	
				}
			}
			curr='z';
			while(curr != d) {
				while(read(0, &curr, 1) > 0) {
					if(curr== d) { break;}
						write(1, &curr, 1);
				}
			}
		}
		 else if(strlen(argv[4]) == 3) {
			int n1 = *argv[4] - '0';	
			int n2 = *(argv[4]+2) - '0';
			char curr;
			int i=0;
			while(i < n1) {
				while(read(0,&curr,1) > 0 ) {
					if(d ==  curr) {
						i++;
					}
				}
			}
			i = 0;
			while( i< (n2 - n1 +1)) {
				while(read(0, &curr, 1) > 0) {
					write(1, &curr, 1);
					if(curr == d) {
						i++;
					}
				}
			}
		
 		}	
	}

	
	exit(0);
}
