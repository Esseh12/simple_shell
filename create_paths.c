#include "main.h"
extern char **environ;
/**
 * create_paths - create a linkedlist of dir
 * @paths: the environ list of path
 * Return: the linkedlist
 */

dirs *create_paths(char *paths)
{
	dirs *head = NULL, *current;
	char *dir;
	char *token;
	char *delim = ":";

	dir = strtok(paths, delim);

	while (dir != NULL)
	{
		dirs *new_dir = (dirs*) malloc(sizeof(dirs)); //allocate memory so we can do new_dir->

		/* initializing the new_dir */
		new_dir->dir = dir;
		new_dir->next = NULL;
		
		if (head == NULL)
		{
			head = new_dir;
			current = new_dir;
		}
		else
		{
			//this is the part where we are inserting a new node
			current->next = new_dir;
			current = new_dir; //keeping track of the current node
		}

		token = strtok(NULL, delim);
	}
}

int main(void)
{
	dirs *paths;
       	char paths_str[1024] = environ[12];
	paths = create_paths(paths_str);

}
