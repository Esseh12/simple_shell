#include "shell.h"

/**
 * execmd - for executing the command
 * @user_input: the command to execute
 *
 * Return: 0 always
 */
void execmd(char *av[])
{
	char *command;
	/** char **commands; 
	char *delim = " ";
	int counter = 0;
	int token_num = 0; */
	int pid;
	char *actual_command;

	/**Remove the \n in the command 
	av[0] = strtok(av[0], "\n"); */

	/** tokenize command using strtok 
	command = strtok(user_input, delim);

	* checking number of words in commands 
	while (command != NULL)
	{
		token_num++;
		command = strtok(NULL, delim);
	
	}

	token_num++;
	 allocate memory for commands 
	commands = malloc(sizeof(char *) * token_num);
	command = strtok(user_input, delim);

	 keep tokenizing the command 
	while (command != NULL)
	{
		commands[counter] = strdup(command);
		command = strtok(NULL, delim);
		counter++;
	}*/

	command = av[0];
	/* create a new process that will execute the command */
	actual_command = get_local(command);
	if (actual_command != NULL)
	{
		pid = fork();
		wait(NULL);

		if (pid == 0)
			if (execve(actual_command, av, NULL) == -1)
				perror("./shell");
	}
	else
		perror("./shell");
	/*av[counter] = NULL;*/
/**
	while (counter--)
	{
		commands[counter] = NULL;
		free(commands[counter]);
	}*/
}
