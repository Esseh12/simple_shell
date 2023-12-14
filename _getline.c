#include "shell.h"

/**
 * _getline - gets a line from stdin
 * @lineptr: pointer to string
 * @n: size of command
 *
 * Return: the number of characters
 * otherwise -1 for error
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	ssize_t nchars = read(0, *lineptr, *n);

	if (nchars == -1)
		return (-1);
	return (nchars);
}
