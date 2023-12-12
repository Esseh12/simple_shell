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

/**
 * struct directories - A node in a linked list of directories
 * @dir: A string representing a directory path
 * @next: A pointer to the next node in the list
 *
 * Description: This struct is used to create a linked list of directories.
 */

typedef struct directories
{
	char *dir;
	struct directories *next;
} dirs;

void execmd(char *user_input);
int handle_env(char **env);

char *get_local(char *command);
#endif /* MAIN_H */
