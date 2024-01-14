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


#if defined(__APPLE__) || defined(linux)
	#define PATH_SEPARATOR '/'
	#define FILE_EXTENSION ".out"
#elif defined(__WIN32)
	#define PATH_SEPARATOR '\\'
	#define FILE_EXTENSION ".exe"
#endif


static char *temp_dir;


int main(int argc, char *argv[]) {
	if(argc != 2) return 2;

	struct stat st;
	if (stat(argv[1], &st) != false) {
		printf("\033[1;31mFILE NOT FOUND\033[0m: { \033[1;36m%s\033[0m }\n", argv[1]);
		return 1;
	}

	size_t len_argv = (strlen(argv[1]) + 1);

	if (strEndWith(argv[1], ".py")) {
		char python_command[len_argv + 9];
		snprintf(python_command, sizeof(python_command), "%s %s", PYTHON, argv[1]);
		printf("[\033[1;35mRUNNING\033[0m] { \033[1;36m%s\033[0m }\n", python_command);
		return system(python_command);
	}
	else if (str_ends_with(argv[1], ".js")) {
		char JScommand[len_argv + 5];
		snprintf(JScommand, sizeof(JScommand), "%s %s", "node", argv[1]);
		printf("[\033[1;35mRUNNING\033[0m] { \033[1;36m%s\033[0m }\n", JScommand);
		return system(JScommand);
	}

	char *file_name;

	if((file_name = strrchr(argv[1], PATH_SEPARATOR)) == NULL) {
		file_name = &(argv[1][0]);
	}
	else {
		file_name++;
	}

	return 0;
}
