#include "main.h"

#define MAX_TOKENS 50
/**
 * main - simple shell
 * @argc: arguments coun
 * @argv: an array of strings of argument
 * @envp: array of strings of environment variables
 *
 * Return: 0 always
 */
int main(int argc, char **argv, char *envp[])
{
	char *user_input;
	char *commands[1024];
	size_t size_of_command = 32;
	const char *str = "#cisfun$ ";
	int pid;

	(void)argc;
	(void)envp;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, str, 9);
			fflush(stdout);

			/* get input from user and also handle EOF or CTRL + D*/
			if (getline(&user_input, &size_of_command, stdin) == -1)
				return (0);
			user_input = strtok(user_input, "\n");

			commands[0] = user_input;
			pid = fork();
			wait(NULL);
			if (pid == 0)
				if (execve(user_input, commands, NULL) == -1)
					perror(argv[0]);

		}
	}
	else
	{
		getline(&user_input, &size_of_command, stdin);

		user_input = strtok(user_input, "\n");
		commands[0] = user_input;
		pid = fork();
		wait(NULL);
		if (pid == 0)
			if (execve(user_input, commands, NULL) == -1)
				perror(argv[0]);
	}
	return (0);
}
