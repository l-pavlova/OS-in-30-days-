//Да се напише програма на C, която изпълнява команда date.
#include <unistd.h>
#include <stdlib.h>
#include <err.h>
int main() {
	if(execlp("date", "date", (char*)NULL) == -1) {
		err(1,"couldn't find executable");
	}

	exit(0);


}
