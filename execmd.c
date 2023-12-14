#include "shell.h"

/**
 * execmd - for executing the command
 * @user_input: the command to execute
 *
 * Return: 0 always
 */
void execmd(char *av[])
{
	char *command = NULL;
	/** char **commands; 
	char *delim = " ";
	int counter = 0;
	int token_num = 0; 
	int pid; */
	char *actual_command = NULL;

	/** command = av[0];
	create a new process that will execute the command 
	actual_command = get_local(command); */
     /**if (actual_command != NULL)
	{
		pid = fork();
		wait(NULL);

		if (pid == 0)

		if (execve(actual_command, av, NULL) == -1)
				perror("./shell");
	}
	else
		perror("./shell");
	av[counter] = NULL;*/
/**
	while (counter--)
	{
		commands[counter] = NULL;
		free(commands[counter]);
	}*/

	if (av){
        /* get the command */
        	command = av[0];

        /* generate the path to this command before passing it to execve */
        	actual_command = get_local(command);

        /* execute the actual command with execve */
        	if (execve(actual_command, av, NULL) == -1){
            		perror("Error:");
        }
    }
} 


