#include "header.h"

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
*
*
*
*/

void op_pop(stack_t **head, unsigned int line_number)
{
        stack_t **temp = head;

        if (!temp)
        {
                line_number = line_number;
                /* error message, pop fail */
        }
        delete_dnodeint_at_index(temp, 0);
}

/**
*
*
*
*/
void op_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!head)
	{
		line_number = line_number;
		/*error message, pint fail */
	}
	printf("%d\n", temp->n);
}

/**
*
*
*
*/

void op_nop(stack_t **head, unsigned int line_number)
{
	head = head;
	line_number = line_number;
}
