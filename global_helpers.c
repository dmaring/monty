#include "monty.h"

/**
 * create_global_struct - function that creates a new dog
 * @linenumber: line number of string
 * @line: pointer to line string
 * @fp: pointer to file descriptor
 * @head: pointer to first element in the stack
 *
 * Return: pointer to new global_struct
 */
global_struct_t *create_global_struct(unsigned int linenumber, char *line,
					 FILE *fp, stack_t *head)
{
	unsigned int ll = 0, i = 0;
	global_struct_t *ptr = NULL;

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

	ptr->fp = fp;

	ptr->head = head;

	return (ptr);
}
