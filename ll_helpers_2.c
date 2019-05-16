#include "header.h"

/**
* get_dnodeint_at_index - return nth node of the list
* @head: pointer to the nodes of the list
* @index: number to return node of in list
*
* Return: head at position of index
*/

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i;

	if (!head)
		return (NULL);

	for (i = 0; head && i < index; i++)
	{
		if (!head->next)
			break;
		head = head->next;
	}
	return (head);
}

/**
* insert_dnodeint_at_index - insert a new node in list at position index
* @h: double pointer to nodes in the list
* @idx: index to insert node at
* @n: number to fill into new node
*
* Return: new node at postion on success, NULL on failure
*/

stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	unsigned int i;
	stack_t *temp = NULL;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new || !h)
		return (NULL);

	new->n = n;
	if (!*h)
	{
		new->next = NULL;
		new->prev = NULL;
		*h = new;
		return (new);
	}

	temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp->next && i <= idx; i++)
	{
		temp = temp->next;

		if (!temp)
			return (NULL);
		if (i == idx - 1)
		{
			new->next = temp->next;
			new->prev = temp->prev;
			temp->prev->next = new;
			temp->next->prev = new;
			return (new);
		}
	}
	if (!temp->next)
		return (add_dnodeint_end(h, n));
	return (NULL);
}

/*add_dnodeint - add a node to the beginning of the list with info
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
* delete_dnodeint_at_index - delete node in list at index
* @head: pointer to nodes in the list
* @index: position to remove node
*
* Return: 1 on success, -1 if failure
*/

void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *curr = NULL;
	stack_t *temp = NULL;

	if (!*head || !head)
		return;

	temp = *head;

	if (index == 0)
	{
		(*head)->prev = NULL;
		*head = (*head)->next;
		free(temp);
		return;
	}
	for (i = 0; i < index - 1; i++)
		temp = temp->next;

	curr = temp->next;
	temp->next = curr->next;
	curr->next->prev = temp;
	free(curr);

	return;
}

/**
* dlistint_len - return length of the linked list
* @h: pointer to the nodes of the list
*
* Return: number of nodes in the list
*/

size_t dlistint_len(const stack_t *h)
{
	stack_t *temp = (stack_t *) h;
	int i;

	for (i = 0; temp; i++)
		temp = temp->next;

	return (i);
}
