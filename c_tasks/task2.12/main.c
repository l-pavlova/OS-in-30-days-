/*Да се напише програма на C, която получава като параметри от команден ред две команди (без параметри) и име на файл в текущата директория. Ако файлът не съществува, го създава. Програмата изпълнява командите последователно, по реда на подаването им. Ако първата команда завърши успешно, програмата добавя нейното име към съдържанието на файла, подаден като команден параметър. Ако командата завърши неуспешно, програмата уведомява потребителя чрез подходящо съобщение.*/
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if(argc != 4) {
		errx(1, "Wrong argument count!");
	}
	int fd=open(argv[3], O_RDWR | O_CREAT | O_TRUNC, 00700);
	if(fd == -1) {
		err(45,"couldnt open file");
	}	
	for(int i=1; i<argc-1;i++) {
		int pid=fork();
		int status;
		if(pid < 0) {
			close(fd);
			err(2,"couldn't fork");
		}
		if(pid==0) {
			if(execlp(argv[i],argv[i], (char*)NULL) !=0) {
				err(3,"couldnt exec %s", argv[i]);
			}
		}
		wait(&status);
		char*buff=malloc(strlen(argv[i]));
		strcpy(buff,argv[i]); 
		if (WIFEXITED(status)) {
			if(WEXITSTATUS(status) == 0) {
				if((write(fd, buff, sizeof(buff))!=sizeof(buff))){
					close(fd);
					free(buff);
					err(4,"coudlnt write the command to file");
				}
			}

		}
	}
		
	
	exit(0);
}
