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
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");

		if (stat(file_path, &st) == 0)
		{
			printf("file is found\n");
		}	
		
		else{
			printf("file not found!\n");
		}
		
		file_path = strtok(NULL, ":");
		
	}
	
}

int main(void)
{
	get_local("anything");
}
