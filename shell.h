#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void execmd(char *av[]);
int handle_env(char **env);

char *get_local(char *command);
#endif /* SHELL_H */
