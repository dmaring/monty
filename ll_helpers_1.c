#include "header.h"

/**
* print_stack_t - print the linked list
* @h: pointer to the nodes of the list
*
* Return: amount of nodes
*/
/*
void print_stack_t(const stack_t *h, int line_number)
{
	int i;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
*/
/**
* stack_t_len - return length of the linked list
* @h: pointer to the nodes of the list
*
* Return: number of nodes in the list
*/
/*
size_t stack_t_len(const stack_t *h)
{
	stack_t *temp = (stack_t *)h;
	int i;

	for (i = 0; temp; i++)
		temp = temp->next;

	return (i);
}
*/
/**
* add_dnodeint - add a node to the beginning of the list with info
* @head: double pointer to the nodes in the list
* @n: number to fill into new node
*
* Return: new node, added to list
*/
/*
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
*/
/**
* add_dnodeint_end - add node to end of linked list
* @head: double pointer to nodes in the list
* @n: number to fill new node with
*
* Return: new node on success, NULL on failure
*/

int add_dnodeint_end(stack_t **head, const int line_number)
{
/*
	stack_t *temp;
	stack_t *new = malloc(sizeof(stack_t));
*/
	char *arg = NULL;
/*	int num;*/
	(void)head;

	printf("we got here\n");

	arg = strtok(global_line, " ");
	arg = strtok(NULL, " ");
	printf("arg = %s\n", arg);

/*	num = atoi(arg);*/

/*
	if (!head || !new)
		return (0);

	temp = *head;

	new->n = num;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (line_number);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
*/
	return (line_number);
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
