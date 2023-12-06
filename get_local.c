#include "main.h"

/**
 * get_local - Get location of command
 * @command: command to be inputed 
 *
 * Return: location of command
 */

char *get_local(char *command)
{
	char *path = getenv("PATH");
	char *file_path = strtok(path, ":");
	struct stat st;

	while (file_path != NULL)
	{
		/* allocate memory */
		char *temp_path = malloc(strlen(file_path) + strlen(command) + 2);

		strcpy(temp_path, file_path);
		strcat(temp_path, "/");
		strcat(temp_path, command);
		strcat(temp_path, "\0");

		if (stat(temp_path, &st) == 0)
		{
			return (temp_path);
		}
		file_path = strtok(NULL, ":");
		
	}
	return (NULL);
	
}
