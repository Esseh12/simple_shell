#include "main.h"

/**
 * handle_env - handle environment variable
 * @env: a constant arr of strings of environment variables
 *
 * Return: 0 on success
 */
int handle_env(char **env)
{
	int count;
	char **copy_env;

	for (count = 0; env[count] != NULL; count++)
	;

	copy_env = malloc(sizeof(char *) * count);

	for (count = 0; env[count] != NULL; count++)
	{
		copy_env[count] = strdup(env[count]);
		strcat(copy_env[count], "\n");
		write(1, copy_env[count], strlen(copy_env[count]));
		free(copy_env[count]);
	}

	free(copy_env);
	return (0);
}
