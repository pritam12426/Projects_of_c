#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "lib/user_function.h"


int main(int argc, const char *argv[]) {
	for (size_t i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	// TODO: Add ad funciton for open a 'UTF-8' text file
	return 0;
}
