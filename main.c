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
	char *user_input = NULL, *command = NULL, *user_input_copy = NULL;
	size_t size_of_command = 32;
	const char *str = "($)  ", *delim = " \n";
	ssize_t num_char;
	int token_num = 0, i;
	(void)ac;
	(void)envp;
	while (1)
	{
		printf("%s", str);
		num_char = getline(&user_input, &size_of_command, stdin);
		if (num_char == -1)
			return (-1);
		user_input_copy = malloc(sizeof(char) * num_char);
		strcpy(user_input_copy, user_input);
		command = strtok(user_input, delim);
		while (command != NULL)
		{
			token_num++;
			command = strtok(NULL, delim);
		}
		token_num++;
		av = malloc(sizeof(char *) * token_num);
		command = strtok(user_input_copy, delim);
		for (i = 0; command != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(command));
			strcpy(av[i], command);
			command = strtok(NULL, delim);
		}
		av[i] = NULL;
		if (strcmp(user_input, "exit") == 0)
			handle_exit(av);
		if (strcmp(user_input, "env") == 0)
			handle_env(envp);
		execmd(av);
	}
	free(user_input);
	free(user_input_copy);
return (0);
}
