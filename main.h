#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct directories {
	char *dir;
	struct directories *next;
} dirs;

int execmd(char *user_input);

extern char **environ;
#endif /* MAIN_H */
