#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct directories {
	char *dir;
	struct directories *next;
} dirs;

void execmd(char *user_input);

char *get_local(char *command);
#endif /* MAIN_H */
