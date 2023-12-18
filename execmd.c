#include "shell.h"

/**
 * execmd - for executing the command
 * @av: the command to execute
 *
 * Return: 0 always
 */
void execmd(char *av[])
{
	char *command = NULL;
	char *actual_command = NULL;

	if (av)
	{
		/* get the command */
		command = av[0];

		/* generate the path to this command before passing it to execve */
		actual_command = get_local(command);

		/* using execve to execute the command */
		if (execve(actual_command, av, NULL) == -1)
			perror("./shell");
	}
}
