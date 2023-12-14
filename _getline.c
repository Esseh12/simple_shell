#include "shell.h"

/**
 * _getline - gets a line from stdin ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 * @lineptr: pointer to string
 * @n: size of command
 * @stream: where to read from
 *
 * Return: the string otherwise -1 for error
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	ssize_t nchars = read(0, *lineptr, *n);
	if (nchars == -1)
		return (-1);
	return (nchars);
}

/*int main(void)
{

	char *user_input = malloc(sizeof(char *) * 10);
        size_t size_of_command = 32;
	ssize_t num_char;

	num_char = _getline(&user_input, &size_of_command);
	printf("%s", user_input);
	printf("%lu\n", num_char);
}*/

/*int main(void)
{
	char *str = malloc(sizeof(char *) * 10);
	read(0, str, 5);

	printf("%s", str);
}*/
