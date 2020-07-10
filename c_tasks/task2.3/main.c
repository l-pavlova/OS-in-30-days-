//Да се напише програма на C, която изпълнява команда sleep (за 60 секунди).

#include <unistd.h>
#include <err.h>
#include <stdlib.h>
int main() {
	if(execlp("sleep", "sleep", "30", (char*) NULL) == -1) {
		err(1, "couldnt exec lol");
	}
	exit(0);
}
