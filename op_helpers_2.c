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
