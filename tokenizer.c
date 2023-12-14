#include "shell.h"

/**
 * tokenizer - tokenizer a string and store in a array
 * @av: the array to store the tokens
 * @token: the string to tokenizer
 *
 * Return: nothing
 */
void tokenizer(char ***av, char *token)
{
	/*char *command;*/
	char *token_copy = NULL;
	char *tok = NULL;
	const char *delim = " \n";
	int token_num = 0, i = 0;

	token_copy = malloc(sizeof(char) * (strlen(token) + 1));
	strcpy(token_copy, token);

	tok = strtok(token, delim);
	while (tok != NULL)
	{
		token_num++;
		tok = strtok(NULL, delim);
	}
	token_num++;

	*av = malloc(sizeof(char *) * token_num);

	tok = strtok(token_copy, delim);
	for (i = 0; tok != NULL; i++)
	{
		(*av)[i] = malloc(sizeof(char) * strlen(tok));
		strcpy((*av)[i], tok);
		tok = strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(token_copy);
}
