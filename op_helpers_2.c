#include "header.h"

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
*
*/

void op_mul(stack_t **head, unsigned int line_number)
{
        stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
        int sum = 0;

        if (dlistint_len(*head) < 2)
        {
                line_number = line_number;
                /*error message, not enough elements*/
        }
        node_0 = get_dnodeint_at_index(*head, 0);
        node_1 = get_dnodeint_at_index(*head, 1);

        prod = node_0->n * node_1->n;
        delete_dnodeint_at_index(head, 0);
        delete_dnodeint_at_index(head, 0);

        new =  add_dnodeint(head, prod);
        if (!new)
        {
                line_number = line_number;
                /*error message, malloc fail */
        }
}

/**
*
*
*
*
*/

void op_mod(stack_t **head, unsigned int line_number)
{
        stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
        int sum = 0;

        if (dlistint_len(*head) < 2)
        {
                line_number = line_number;
                /*error message, not enough elements*/
        }
        node_0 = get_dnodeint_at_index(*head, 0);
        node_1 = get_dnodeint_at_index(*head, 1);

        sum = node_0->n % node_1->n;
        delete_dnodeint_at_index(head, 0);
        delete_dnodeint_at_index(head, 0);

        new =  add_dnodeint(head, sum);
        if (!new)
        {
                line_number = line_number;
                /*error message, malloc fail */
        }
}
