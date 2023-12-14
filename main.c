#include "shell.h"
/**
 * main - simple shell
 * @ac: arguments coun
 * @av: an array of strings of argument
 * @envp: array of strings of environment variables
 * Return: 0 always
 */
int main(int ac, char **av, char *envp[])
{
	char *user_input = NULL; /**command = NULL, *user_input_copy = NULL;*/
	size_t size_of_command = 32;
	const char *str = "($)  ";/* *delim = " \n";*/
	ssize_t num_char;
	/*int token_num = 0, i = 0;*/
	(void)ac;
	(void)envp;
	while (1)
	{
		printf("%s", str);
		num_char = getline(&user_input, &size_of_command, stdin);
		if (num_char == -1)
			return (-1);

		tokenizer(&av, user_input);

		if (strcmp(av[0], "cd") == 0)
			change_dir(av[1]);
		else if (strcmp(user_input, "exit") == 0)
			handle_exit(av);
		else if (strcmp(user_input, "env") == 0)
		{
			handle_env(envp);
			execmd(av);
		}
		else
			execmd(av);
	}
	free(user_input);
	/*free(user_input_copy);*/
	return (0);
}
