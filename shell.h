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
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *get_local(char *command);
ssize_t _getline(char **lineptr, size_t *n);
void handle_exit(char **av);
void tokenizer(char ***av, char *token);
void change_dir(char *dir);
#endif /* SHELL_H */
