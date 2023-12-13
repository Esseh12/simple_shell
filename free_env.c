#include "shell.h"

/**
 * free_env - free environment variables
 * @envp: the environment variables
 *
 * Return: nothing
 */
void free_env(char **envp)
{
	int i;

	if (envp == NULL)
		return;

	for (i = 0; envp[i] != NULL; i++)
		free(envp[i]);

	free(envp[i]);
}
