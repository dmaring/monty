#include "header.h"

/**
* get_dnodeint_at_index - return nth node of the list
* @head: pointer to the nodes of the list
* @index: number to return node of in list
*
* Return: head at position of index
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
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
* sum_dlistint - add all numbers in nodes of list
* @head: pointer to the nodes in the list
*
* Return: sum of numbers
*/

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

/**
* insert_dnodeint_at_index - insert a new node in list at position index
* @h: double pointer to nodes in the list
* @idx: index to insert node at
* @n: number to fill into new node
*
* Return: new node at postion on success, NULL on failure
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *temp = NULL;
	dlistint_t *new = malloc(sizeof(dlistint_t));

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

/**
* delete_dnodeint_at_index - delete node in list at index
* @head: pointer to nodes in the list
* @index: position to remove node
*
* Return: 1 on success, -1 if failure
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *curr = NULL;
	dlistint_t *temp = NULL;

	if (!*head || !head)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		(*head)->prev = NULL;
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	for (i = 0; i < index - 1; i++)
		temp = temp->next;

	curr = temp->next;
	temp->next = curr->next;
	curr->next->prev = temp;
	free(curr);

	return (1);
}
