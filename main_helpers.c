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
		{"", va_print_i},
		{"d", va_print_i},
		{"b", va_print_b},
		{"R", va_print_rot13},
		{NULL, NULL}
	};

	int i = 0;

	/** loop through fmatters id member **/
	while (printers[i].id)
	{
		if (*s == *(printers[i].id))
			break;
		i++;
	}

	return (printers[i].f);
}
