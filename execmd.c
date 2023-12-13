#include "main.h"

/**
 * execmd - for executing the command
 * @user_input: the command to execute
 *
 * Return: 0 always
 */
void execmd(char *user_input)
{
	char *command;
	char *commands[1024];
	char *delim = " ";
	int counter = 0;
	int pid;
	char *actual_command;

	/* Remove the \n in the command */
	user_input = strtok(user_input, "\n");

	/* tokenize command using strtok */
	command = strtok(user_input, delim);

	/* keep tokenizing the command */
	while (command != NULL)
	{
		commands[counter] = strdup(command);
		command = strtok(NULL, delim);
		counter++;
	}

	/* create a new process that will execute the command */
	/*actual_command = get_local(commands[0]);*/
	actual_command = user_input;
	if (actual_command != NULL)
	{
		pid = fork();
		wait(NULL);

	if (pid == 0)
		if (execve(actual_command, commands, NULL) == -1)
			perror("./shell");
	}
	else
		perror("./shell");

	while (counter--)
	{
		commands[counter] = NULL;
		free(commands[counter]);
	}
}
