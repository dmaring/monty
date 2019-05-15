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
	stack_t *head = NULL;
	char *line = NULL;
/*	char **opcodes = NULL;*/
	size_t len = 0;
	ssize_t read;
	unsigned int linenumber = 0;
	void (*opfunc)(stack_t **head, unsigned int linenumber);
	(void)argc;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		linenumber++;
		/* remove nl from line */
		rm_nl(&line);
		/* check if line is blank */
		if (wordcount(line) == 0)
			break;
		/* add line and line number to global_struct */
		global_struct = create_global_struct(linenumber, line);
		/* TEST only for global struct members */
		/* printf("Full Line: %s\n", global_struct->line); */
		/* printf("Line Number: %d\n", global_struct->linenumber); */
		/* printf("Arg 1: %s\n", global_struct->arg_list[0]); */
		/* printf("Arg 2: %s\n", global_struct->arg_list[1]); */
		/* get function for opcode */
		/* op_func = get_op_func(opcodes[0]); */
		opfunc = get_op_func(global_struct->arg_list[0]);
		if (opfunc == NULL)
		{
			free_all(head, line, fp);
			/* print error message */
			exit(1);
		}
		/*  do something*/
		opfunc(&head, global_struct->linenumber);

		free_global_struct(global_struct);

	}
<<<<<<< HEAD
	free_all(head, line, fp);
=======

	free_stack_t(head);
	free(line);
	fclose(fp);

>>>>>>> 6d544cda38ef088b9ba66475dee8d7f89e388bed
	exit(EXIT_SUCCESS);
}
