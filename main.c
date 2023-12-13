#include "shell.h"

#define MAX_TOKENS 50
/**
 * main - simple shell
 * @ac: arguments coun
 * @av: an array of strings of argument
 * @envp: array of strings of environment variables
 *
 * Return: 0 always
 */
int main(int ac, char **av, char *envp[])
{
	char *user_input;
	size_t size_of_command = 32;
	const char *str = "($)  ";

	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, str, 4);
			fflush(stdout);

			/* get input from user and also handle EOF or CTRL + D*/
			if (getline(&user_input, &size_of_command, stdin) == -1)
				break;

			/* exiting the shell */
			if (strcmp(user_input, "exit\n") == 0)
				break;

			/* handling the builtin env */
			if (strcmp(user_input, "env\n") == 0)
				handle_env(envp);

			/* execute the command */
			execmd(user_input, av);
		}

		free(user_input);
	}
	else
	{
		getline(&user_input, &size_of_command, stdin);

		/* calling the execmd function */
		execmd(user_input, av);

		free(user_input);
	}

	free_env(envp);
	return (0);
}
