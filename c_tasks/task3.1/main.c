//T1 - Да се напише програма на C, която приема аргумент - име на файл. Програмата да:
//записва във файла 'fo'
//създава child процес, който записва 'bar\n'
//parent-а, след като изчака child процеса, записва 'o\n'
int main(int argc, char* argv[]) {
 	if(argc !=2) {
		errx(1, "Wrong arument count!");
	}
	int fd=open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(fd == -1) {
		err(2, "Couldn't open file.");
	}
	const char str[] = "fo";
	const char str2[] = "bar\n";
	if(write(fd, str, 2) !=2) {
		close(fd);
		err(3,"Couldnt write fo from parent");
	}
	pid_t kidpid=fork();
	if(kidpid < 0) {
		close(fd);
		err(4, "failed to fork!");
	}
	if(kidpid == 0) {
		if(write(fd, str2, sizeof(str2)) != sizeof(str2)) {
			err(5, "failed to write from child");
		}
		exit(0);
	}
	int status;
	const pid_t res = wait(NULL);
//?	if(status < 0) {
	if(WIFEXITED(status)	


}
