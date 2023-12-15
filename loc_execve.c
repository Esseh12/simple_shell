#include "shell.h"

/**
 * loc_execve - using the execve function
 *@av: an array of argument
 *@command: the command to execute
 *
 * Return: 0 Always
 */

void loc_execve(char *command, char *av[])
{
	pid_t pid;

	pid = fork();
	/* parent process */
	if (pid != 0)
		wait(NULL);
	/* child process */
	if (pid == 0)
	/* execute the actual command with execve */
		if (execve(command, av, NULL) == -1)
			perror("./shell");
}	
