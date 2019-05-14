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
	char *line = NULL;
	size_t len = 0;

	fp = fopen(argv[1], "r");
	if (fp = NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		/* parse */

		free(line);
	}

	exit(EXIT_SUCCESS);
}
