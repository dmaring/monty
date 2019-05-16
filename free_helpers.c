#include "monty.h"
/**
* free_all - free elements in the list
* @head: pointer to nodes in the list
* @line: input line
* @fp: file pointer to open file
*
* Return: void
*/

void free_all(int flag)
{
	stack_t *temp;

	while (global_struct->head)
	{
		temp = global_struct->head->next;
		free(global_struct->head);
		global_struct->head = temp;
	}
	free_global_struct(global_struct);

	if (flag == 1)
	{
		if (global_struct->fp)
		{
			fclose(global_struct->fp);
			global_struct->fp = NULL;
		}
	}
}

/**
 * free_global_struct - function that frees global struct
 * @ptr: pointer to global struct instance
 *
 */
void free_global_struct(global_struct_t *ptr)
{
	int i = 0;

	if (ptr)
	{
		while (ptr->arg_list[i])
		{
			free(ptr->arg_list[i]);
			i++;
		}
		free(ptr->arg_list);
		free(ptr);
	}
	ptr = NULL;
}
