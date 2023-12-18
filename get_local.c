#include "shell.h"

/**
 * get_local - Get location of command
 * @command: command to be inputed
 *
 * Return: location of command
 */

char *get_local(char *command)
{
	char *path = getenv("PATH");
	char *file_path = strdup(path);
	char *path_token = strtok(file_path, ":");
	struct stat st, st_t;
	char *temp_path;

	if (path == NULL)
	{
		free(file_path);
		return (NULL);
	}	

	while (path_token != NULL)
	{
		/* allocate memory */
		temp_path = malloc(strlen(file_path) + strlen(command) + 2);

		if (temp_path == NULL)
		{
			free(temp_path);
			return (NULL);
		}

		if (stat(command, &st_t) == 0)
		{
			free(file_path);
			free(temp_path);
			return (command);
		}

		strcpy(temp_path, path_token);
		strcat(temp_path, "/");
		strcat(temp_path, command);

		if (stat(temp_path, &st) == 0)
		{
			free(file_path);
			return (temp_path);
		}

		free(temp_path);
		path_token = strtok(NULL, ":");
	}

	free(file_path);
	return (NULL);
}
