#include "header.h"

/**
 * main - main function for Monty interpreter
 * @argc: number of arguments passed to the program
 * @argv: vector of list of pointers to arguments passed
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t **head;
	char *line = NULL;
	char **opcodes = NULL;
	size_t len = 0;
	ssize_t read;
	size_t linenumber = 0;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		linenumber++;
		printf("Readline: %s\n", line);
		/* get function for opcode */
		/* op_func = get_op_func(opcodes[0]); */
		/* store somewhere if push or do something*/
		if (strncmp(line, "push", 4) == 0)
			printf("Push found!");

		free(line);
	}
	fclose(fp);




	exit(EXIT_SUCCESS);
}
