#include "monty.h"

/**
 * create_global_struct - function that creates a new global_struct
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
	global_struct_t *ptr = NULL;

	ptr = malloc(sizeof(global_struct_t));
	if (ptr == NULL)
		return (NULL);

	ptr->line = line;
	ptr->linenumber = linenumber;

	ptr->arg_list = strtow(line);

	ptr->fp = fp;

	ptr->head = head;

	return (ptr);
}
