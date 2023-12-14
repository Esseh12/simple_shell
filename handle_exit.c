#include "shell.h"

/**
 * handle_exit - exit the shell with status code
 * @av: array holding the arg including status code
 *
 * Return: nothing
 */
void handle_exit(char **av)
{
	int status;

	if (av[1] != NULL)
	{
		status = atoi(av[1]);
		exit(status);
	}
	else
		exit(0);
}
