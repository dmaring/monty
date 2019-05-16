#include "monty.h"

/**
* add_dnodeint_end - add node to end of linked list
* @head: double pointer to nodes in the list
* @n: number to fill new node with
*
* Return: new node on success, NULL on failure
*/

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *new = malloc(sizeof(stack_t));

	if (!head || !new)
		return (NULL);

	temp = *head;

	new->n = n;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
* free_all - free elements in the list
* @head: pointer to nodes in the list
* @line: input line
* @fp: file pointer to open file
*
* Return: void
*/

void free_all(stack_t *head, char *line, FILE *fp)
{
	stack_t *temp;

	free(line);
	fclose(fp);

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
