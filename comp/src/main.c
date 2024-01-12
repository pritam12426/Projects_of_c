#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "./lib/user_function.h"


int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strEndWith(argv[i], ".c")) {
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}

