#include "monty.h"

global_struct_t *global_struct = NULL;

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
	size_t len = 0;
	ssize_t read = 0;
	unsigned int linenumber = 0;
	void (*opfunc)(stack_t **head, unsigned int linenumber) = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, argv[1]);
		exit(EXIT_FAILURE);
	}
	global_struct = create_global_struct(linenumber,
			 line, fp, head);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		global_struct->line = line;
		global_struct->fp = fp;
		linenumber++;
		/* remove nl from line */
		rm_nl(&line);
		/* check if line is blank */
		if (wordcount(line) == 0)
		{
			free(line);
			fclose(fp);
			dprintf(STDERR_FILENO, USAGE);
			exit(EXIT_FAILURE);
		}
		/* add line and line number to global_struct */

		opfunc = get_op_func(global_struct->arg_list[0]);
		if (opfunc == NULL)
		{
			dprintf(STDERR_FILENO, UNKNOWN,
				global_struct->linenumber,
				global_struct->arg_list[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		opfunc(&head, global_struct->linenumber);
		free_all(0);
	}
	fclose(fp);
	fp = NULL;
	exit(EXIT_SUCCESS);
}
