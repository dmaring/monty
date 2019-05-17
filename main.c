#include "monty.h"

global_struct_t global_struct;

/**
 * main - main function for Monty interpreter
 * @argc: number of arguments passed to the program
 * @argv: vector of list of pointers to arguments passed
 * Return: 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
/*i	FILE *fp;
	stack_t *head = NULL;
	char *line = NULL;
*/
	size_t len = 0;


	ssize_t read = 0;
/*
	unsigned int linenumber = 1;
*/
	void (*opfunc)(stack_t **head, unsigned int linenumber) = NULL;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	global_struct.fp = fopen(argv[1], "r");
	if (global_struct.fp == NULL)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, argv[1]);
		exit(EXIT_FAILURE);
	}
/*	global_struct = create_global_struct(linenumber,
			 line, fp, head);
*/
	while ((read = getline(&global_struct.line, &len, global_struct.fp)) != -1)
	{
		rm_nl(&global_struct.line);
		global_struct.linenumber++;
		if (wordcount(global_struct.line) == 0)
		{
			free_all();
			dprintf(STDERR_FILENO, USAGE);
			exit(EXIT_FAILURE);
		}
		strtok_list(global_struct.line);
		if (!global_struct.arg)
			continue;
		opfunc = get_op_func(global_struct.arg);
		
		if (opfunc == NULL)
		{
			dprintf(STDERR_FILENO, UNKNOWN,
				global_struct.linenumber,
				global_struct.arg);
			free_all();
			exit(EXIT_FAILURE);
		}

		opfunc(&global_struct.head, global_struct.linenumber);
	}
	free_all();
	exit(EXIT_SUCCESS);
}
