#include "monty.h"

/**
* op_push - add a node to the head of the stack
* @head: double pointer to the nodes in the list
* @line_number: line read
*
* Return: void
*/

void op_push(stack_t **head, unsigned int line_number)
{
	int data = 0;
	stack_t *new = malloc(sizeof(stack_t));
	char *num = strtok(NULL, " \t\n");

	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (num && num[0] == '-')
		data++;

	while (num && num[data])
		if (!isdigit(num[data++]))
		{
			data = -1;
			break;
		}
	if (!num || data == -1)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	data = atoi(num);
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
* op_pall - print the linked list
* @h: pointer to the first element in the stack
* @line_number: pointer to the nodes of the list
*
* Return: void
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
* op_pop - remove most recenet element on the stack
* @head: pointer to first element of the stack
* @line_number: line read
*
* Return: void
*/

void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t **temp = head;

	if (!*temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(temp, 0);
}

/**
* op_pint - print first element of the stack
* @head: pointer to first element on the stack
* @line_number: line read
*
* Return: void
*/
void op_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
* op_nop - function that doesnt do anything
* @head: pointer to first element in the stack
* @line_number: line read
*
* Return: void
*/

void op_nop(stack_t **head, unsigned int line_number)
{
	head = head;
	line_number = line_number;
}
