#include "shell.h"


/* #define MAX_TOKENS 50 */
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
	char *user_input = NULL;
	size_t size_of_command = 32;
	const char *str = "($)  ";
	char *user_input_copy = NULL;
	ssize_t num_char;
	char *command = NULL;
	char *delim = ":";
	int token_num = 0;
	int counter = 0;

	(void)ac;

		while (1)
		{
			write(1, str, 4);
			/* get input from user and also handle EOF or CTRL + D*/
			num_char = getline(&user_input, &size_of_command, stdin);
			if (num_char == -1)
				return (-1);
			/* exiting the shell */
			/* allocate a space for user_input_copy */
			user_input_copy = malloc(sizeof(char) * num_char);
			strcpy(user_input_copy, user_input);

			 command = strtok(user_input, delim);

        		/* checking number of words in commands */
        	while (command != NULL)
        	{
                	token_num++;
                	command = strtok(NULL, delim);

        	}

        	token_num++;
        	/* allocate memory for commands */
        	av = malloc(sizeof(char *) * token_num);
        	command = strtok(user_input_copy, delim);

        /* keep tokenizing the command */
        	while (command != NULL)
        	{
			
                	av[counter] = malloc(sizeof(char) * strlen(command));
			strcpy(av[counter], command);
                	command = strtok(NULL, delim);
                	counter++;
        	}
		av[counter] = NULL;
		counter = 0;

			if (strcmp(user_input, "exit\n") == 0)
				return (0);

			/* handling the builtin env */
			if (strcmp(user_input, "env\n") == 0)
				handle_env(envp);

			/* execute the command */
			execmd(av);
			free(user_input_copy);
		}
		free(user_input);
	/**else
	{
		num_char = getline(&user_input, &size_of_command, stdin);
		user_input_copy = malloc(sizeof(char) * num_char);
		strcpy(user_input_copy, user_input);
		
		 calling the execmd function 
		execmd(user_input_copy);
		free(user_input_copy);
		free(user_input);
} */

	return (0);
}
