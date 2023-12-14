#include "shell.h"

/**
 * change_dir - Changes the current directory of the process.
 * @dir: the dir
 *
 * Return: nothing
 */
void change_dir(char *dir)
{
	char *new_dir;

	if (dir == NULL)
		new_dir = getenv("HOME");
	else if (strcmp("-", dir) == 0)
		new_dir = getenv("OLDPWD");
	else
		new_dir = dir;

	if (chdir(new_dir) == -1)
		perror("cd");
}
