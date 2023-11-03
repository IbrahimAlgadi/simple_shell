#include "main.h"

/**
 * read_user_input - reads the input string.
 *
 * @gt_line: return value of getline function
 *
 * Return: input string
 */
char *read_user_input(int *gt_line)
{
	char *input = NULL;
	size_t bufsize = 0;

	*gt_line = getline(&input, &bufsize, stdin);

	return (input);
}
