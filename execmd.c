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
	pid_t pid;
	int status;

	if (av)
	{
		pid = fork();
		if (pid == 0)
		{
			/* get the command */
			command = av[0];

			/* generate the path to this command before passing it to execve */
			actual_command = get_local(command);

			/* execute the actual command with execve */
			if (execve(actual_command, av, NULL) == -1)
				perror("./shell");
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
