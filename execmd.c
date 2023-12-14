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
	int pid; 
	char *actual_command = NULL;

	if (av){
        /* get the command */
        	command = av[0];

        /* generate the path to this command before passing it to execve */
        	actual_command = get_local(command);

		pid = fork();
		/* parent process */
		if (pid != 0)
			wait(NULL);
		/* child process */
		if (pid == 0)
			/* execute the actual command with execve */
        		if (execve(actual_command, av, NULL) == -1){
            			perror("Error:");
        }
    }
} 
