#include "header.h"

/**
* print_stack_t - print the linked list
* @h: pointer to the nodes of the list
*
* Return: amount of nodes
*/

void op_pall(stack_t **h, unsigned int line_number)
{
	int i;
	stack_t *temp = *h;
	line_number = line_number;

	for (i = 0; temp; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* add_dnodeint - add a node to the beginning of the list with info
* @head: double pointer to the nodes in the list
* @n: number to fill into new node
*
* Return: new node, added to list
*/

void op_push(stack_t **head, unsigned int line_number)
{
	int data = 0;
	stack_t *new = malloc(sizeof(stack_t));
	line_number = line_number;

	if (!new)
		return;
	if (global_struct->arg_list[1] && _isnum(global_struct->arg_list[1][0]))
		data = atoi(global_struct->arg_list[1]);
	else
	{
		/* throw error */
		fprintf(stderr,
			"L%d: usage: push integer\n",
			global_struct->linenumber);
		free(new);
		exit(EXIT_SUCCESS);
	}

	new->n = data;
	new->prev = NULL;
	new->next = NULL;

	if (*head)
	{
		(*head)->prev = new;
		new->next = *head;
	}
	*head = new;

}

/**
* add_dnodeint_end - add node to end of linked list
* @head: double pointer to nodes in the list
* @n: number to fill new node with
*
* Return: new node on success, NULL on failure
*/
/*
int add_dnodeint_end(stack_t **head, const int line_number)
{
	int i;

	stack_t *temp;
	stack_t *new = malloc(sizeof(stack_t));
*/
/*	int num;*/
/*
	(void)head;

	printf("we got here\n");

	for (i = 0; arg_list[i]; i++)
		printf("arg = %s\n", arg_list[i]);

*/
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
/*
	return (line_number);
}
*/
/**
* free_stack_t - free elements in the list
* @head: pointer to nodes in the list
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
