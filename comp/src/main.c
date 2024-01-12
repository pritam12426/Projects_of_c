#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "./lib/user_function.h"


#if defined(__APPLE__) || defined(linux)
	#define PYTHON "python3"
#elif defined(__WIN32)
	#define PYTHON "python"
#endif



int main(int argc, char *argv[]) {
	if(argc != 2) return 2;

	struct stat st;
	if(stat(argv[1], &st) != false) {
		printf("\033[1;31mFILE NOT FOUND\033[0m: { \033[1;36m%s\033[0m }\n", argv[1]);
		return 1;
	}
	
	size_t len_argv = (strlen(argv[1]) + 1);

	if (strEndWith(argv[1], ".py")) {
		char python_command[len_argv + 9];
		printf("[\033[1;35mTRYING TO COMPILE\033[0m] { \033[1;36m%s\033[0m }\n", python_command);
		sprintf(python_command, "%s %s", PYTHON, argv[1]);
		return system(python_command);
	}

	return 0;
}
