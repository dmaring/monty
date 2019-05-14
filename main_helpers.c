#include "header.h"

/**
 * get_op_func - selects correct function for format
 * @s: input opcode
 *
 * Return: pointer to matching function
 */
int (*get_op_func(const char *s))(char *)
{
	/** initialize struct of print and format functions **/
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	int i = 0;

	/** loop through fmatters id member **/
	while (instructions[i].opcode)
	{
		if (*s == *(instructions[i].opcode))
			break;
		i++;
	}

	return (instructions[i].f);
}
