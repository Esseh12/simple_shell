#include "main.h"
#define MAX_TOKENS 1
/**
 * main - simple shell
 * @ac: arguments coun
 * @av: an array of strings of argument
 *
 * Return: 0 always
 */
int main(int ac, char **av)
{
	char *user_input;
	size_t size_of_command = 32;
	char *command;
	char *commands[1024];
	char *delim = " ";
	int counter = 0;
	const char *str = "$ ";
	int pid;

	if (isatty(STDIN_FILENO)){
		while (1)
		{
			counter = 0;
			write(1, str, 2);
	
			/* get input from user and also handle EOF or CTRL + D*/
			if (getlinei(&user_input, &size_of_command, stdin) == -1)
				return (0);
	
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
	
			/* handle number of arguments */
			/* I comments out this code since */
			/* if (execve(commands[0], commands, NULL) == -1)*/
			/* will do the same thing*/
			/* but it works you comment it out and see.*/
			/*if (commands[1] != NULL)*/
			/*	perror("./shell: No such file or directory");*/
	
			/* create a new process that will execute the command */
			pid = fork();
			wait(NULL);
			if (pid == 0)
				if (execve(commands[0], commands, NULL) == -1)
					perror("./shell: No such file or directory");
	
			while (counter--)
				commands[counter] = NULL;
	
		}
	}
	else
	{
		
	}
	return (0);
}










