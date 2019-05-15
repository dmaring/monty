#include "header.h"
global_struct_t *global_struct;

/**
 * main - main function for Monty interpreter
 * @argc: number of arguments passed to the program
 * @argv: vector of list of pointers to arguments passed
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t **head = NULL;
	char *line = NULL;
	char **opcodes = NULL;

	size_t len = 0;
	ssize_t read;
	size_t linenumber = 0;
	(void)argc;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		linenumber++;
		/* remove nl from line */
		rm_nl(&line);
		/* add line and line number to global_struct */
		global_struct = create_global_struct(linenumber, line);
		/* TEST only for global struct members */
		printf("Full Line: %s\n", global_struct->line);
		printf("Line Number: %d\n", global_struct->linenumber);
		printf("Arg 1: %s\n", global_struct->arg_list[0]);
		printf("Arg 2: %s\n", global_struct->arg_list[1]);
		/* get function for opcode */
		/* op_func = get_op_func(opcodes[0]); */
		/* store somewhere if push or do something*/
		if (strncmp(global_struct->line, "push", 4) == 0)
			printf("Push found!");
		free_global_struct(global_struct);
		free(line);
	}
	fclose(fp);

	exit(EXIT_SUCCESS);
}
