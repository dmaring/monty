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
	stack_t *temp = NULL;
	int i = 0;

	if (flag == 1)
	{
		while (global_struct->head)
		{
			temp = global_struct->head->next;
			free(global_struct->head);
			global_struct->head = temp;
		}
		global_struct->head = NULL;

		if (global_struct->fp)
		{
			fclose(global_struct->fp);
			global_struct->fp = NULL;
		}
	}
	if (global_struct->line && global_struct->arg_list[i])
	{
		while (global_struct->arg_list[i])
		{
			free(global_struct->arg_list[i]);
			i++;
		}
		global_struct->arg_list = NULL;
		free(global_struct->line);
		global_struct->line = NULL;

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
		if (ptr->line)
		{
			free(ptr->line);
			ptr->line = NULL;
		}
		free(ptr->arg_list);
		ptr->arg_list = NULL;
		free(ptr);
	}
	ptr = NULL;
}
