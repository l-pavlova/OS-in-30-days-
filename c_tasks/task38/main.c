#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>
#include <stdbool.h>
#include <string.h>
int main(int argc, char* argv[]) {
	if(argc < 2) {
		errx(1, "please enter valid command input, [option]	set1 [set2]");
	}
	bool delete = false;
	bool squeez = false;
	int i = 1;
	if(i == 1) {
		if(strcmp(argv[i], "-d") == 0) {
			delete = true;
			i++;
		} else if(strcmp(argv[i], "-s") == 0) {
			squeez = true;
			i++;
		}
	}
	char* set1 = malloc(strlen(argv[i]));
	strcpy(set1, argv[i]);
	printf("set 1: %s\n", set1);
	i++;
	char* set2 = NULL;
	if(delete || squeez) {
		if(argc == 4) {
			set2 = malloc(strlen(argv[i]));
			strcpy(set2, argv[i]);
		}
		
	} else if(argc == 3) {
			set2 = malloc(strlen(argv[i]));
			strcpy(set2, argv[i]);
			printf("set 2: %s\n", set2);
	}
	if(delete) {
		char c;
		while(read(0,&c, 1) == 1) {
			char* here = strchr(set1, c);
			if(here == NULL) {
				write(1, &c, 1);
			} 	  
		}
	} else if(squeez) {
		char c;
		while(read(0, &c, 1) == 1) {
			char* here = strchr(set1, c);		
			if(here!=NULL) {
				char t;
				read(0, &t, 1);
				if(t==c) {
					while(read(0, &t, 1) == 1 ) {
					 if(t != c ) {
						break;

					}
				}
				lseek(0, -1, SEEK_CUR);//go one back and then print it out
			}
			}//todo:fix this if you pass, fix it if you dont too
			write(1, &c, 1);
		}
	} else {
		char c;
		while(read(0, &c, 1) == 1) {
			for(size_t i = 0; i<strlen(set1); i++) {
				if(c ==set1[i]) {
					c=set2[i];
				}
			}
			write(1, &c, 1);
		}
	}
	exit(0);
}
