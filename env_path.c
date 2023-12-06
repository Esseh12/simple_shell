#include "main.h"

/**
 * env_path - handle paths
 *@command: the command that the user enters
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

/**
 * main - Entry point of the program
 *
 * Description: It calls the env_path function.
 *
 * Return: 0
 */

int main(void)
{
	env_path("Hello world");
}
