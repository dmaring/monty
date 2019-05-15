#include "header.h"

/**
 * wordcount - finds words within string
 * @str: string being passed to check for words
 *
 * Return: number of words
 */

int wordcount(char *str)
{
	int num = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (*str == ' ')
			str++;
		else
		{
			while (str[i] != ' ' && str[i])
			{
				i++;
				str++;
			}
			num++;
		}
	}
	return (num);
}

/**
* strtow - convert input str into a double string
* @str: string to separate
*
* Return: double pointer to the words on success, null if fail
*/

char **strtow(char *str)
{
	char *cpy, **words;
	int i = 0, j = 0, len = 0, total = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	total = wordcount(str);
	if (total == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && i < total)
	{
		if (*str == ' ')
			str++;
		else
		{
			cpy = str;
			while (*str != ' ' && *str)
			{
				len++;
				str++;
			}
			words[i] = malloc(sizeof(char) * (len + 1));
			while (*cpy != ' ' && *cpy)
			{
				words[i][j] = *cpy;
				cpy++;
				j++;
			}
			words[i][j] = '\0';
			i++;
			j = 0;
			len = 0;
		}
	}
	return (words);
}

/**
 * rm_nl - remove the last character newline from string
 * @lineptr: double pointer to string
 */
void rm_nl(char **lineptr)
{
	char *ptr;
	int i;

	ptr = *lineptr;

	i = 0;
	while (ptr[i] != '\n')
		i++;
	ptr[i] = '\0';
}

/**
 * _strlen - find the length of a string
 * @s: pointer to string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return(i);
}
