#include "main.h"

extern char **environ;

/**
 * env_path - handle paths
 * @command: the command that the user enters
 *
 * Return: nothing
 */
void env_path(char *command)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[12]);
	}
}

int main(void)
{
	env_path("Hello world");
}
