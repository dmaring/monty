#include "header.h"

/**
* print_stack_t - print the linked list
* @h: pointer to the nodes of the list
*
* Return: amount of nodes
*/

size_t print_stack_t(const stack_t *h)
{
	int i;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}

/**
* stack_t_len - return length of the linked list
* @h: pointer to the nodes of the list
*
* Return: number of nodes in the list
*/

size_t stack_t_len(const stack_t *h)
{
	stack_t *temp = (stack_t *)h;
	int i;

	for (i = 0; temp; i++)
		temp = temp->next;

	return (i);
}

/**
* add_dnodeint - add a node to the beginning of the list with info
* @head: double pointer to the nodes in the list
* @n: number to fill into new node
*
* Return: new node, added to list
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

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
* free_stack_t - free elements in the list
* @head: pointer to nodes in the list
*
* Return: void
*/

void free_stack_t(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
