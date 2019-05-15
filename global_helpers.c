#include "header.h"

/**
 * new_global_struct - function that creates a new dog
 * @linenum: line number of string
 * @line: pointer to line string
 *
 * Return: pointer to new global_struct
 */
global_struct_t *create_global_struct(unsigned int linenumber, char *line)
{
	unsigned int ll, i;
	global_struct_t *ptr = NULL;
/*	char **arg_list = NULL;*/

	ptr = malloc(sizeof(global_struct_t));
	if (ptr == NULL)
		return (NULL);

	ll = _strlen(line) + 1;
	ptr->line = malloc(ll * sizeof(char));
	if (ptr->line == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < ll; i++)
		ptr->line[i] = line[i];

	ptr->linenumber = linenumber;

	ptr->arg_list = strtow(line);

	return (ptr);
}


/**
 * free_global_struct - function that frees global struct
 * @d: pointer to global struct instance
 *
 */
void free_global_struct(global_struct_t *ptr)
{
	int i = 0;

	if (ptr)
	{
		free(ptr->line);
		while (ptr->arg_list[i])
		{
			free(ptr->arg_list[i]);
			i++;
		}
		free(ptr->arg_list);
		free(ptr);
	}
}
