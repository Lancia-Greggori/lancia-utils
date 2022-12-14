#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int size = 0;
	if (argc <= 1) return 1;
	for (int i = 1; i < argc; i++) {
		size = size + strlen(argv[i]);
		if (i != argc-1) size++; // account for spaces between arguments
	}

	char command[size+6]; // account for the string "curl " plus NULL terminator
	strcpy(command, "curl ");
	for (int i = 1; i < argc; i++) {
		strcat(command, argv[i]);
		if (i != argc-1) strcat(command, " ");
	}

	return 0;
}
