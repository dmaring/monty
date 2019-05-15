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

	global_struct = malloc(sizeof(instruction_t));
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		linenumber++;
		printf("Readline: %s\n", line);
		/* add line to global_struct */
		/* add line number to global struct */
		/* get function for opcode *//
		/* op_func = get_op_func(opcodes[0]); */
		/* store somewhere if push or do something*/
		if (strncmp(line, "push", 4) == 0)
			printf("Push found!");
		free(line);
	}
	free(global_struct);
	fclose(fp);




	exit(EXIT_SUCCESS);
}
