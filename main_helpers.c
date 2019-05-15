#include "header.h"

/**
 * get_op_func - selects correct function for format
 * @s: input opcode
 *
 * Return: pointer to matching function
 */
void (*get_op_func(char *s))(stack_t **head, unsigned int linenumber)
{
	/** initialize struct of opcode functions **/
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		/* {"pint", op_pint}, */
		/* {"pop", op_pop}, */
		/* {"swap", op_swap}, */
		/* {"add", op_add}, */
		/* {"nop", op_nop}, */
		{NULL, NULL}
	};

	int i = 0;

	/** loop through instructions opcode member **/

	while (instructions[i].opcode)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
			break;
		i++;
	}

	return (instructions[i].f);
}
