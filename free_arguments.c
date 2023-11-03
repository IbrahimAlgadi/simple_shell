#include "main.h"

/**
 * free_arguments - Free Allocated Memory Arguments
 *
 * @arguments: the memory allocated for input string
 * passed by the shell user
 *
 * Return: Always 0
 */
void free_arguments(char **arguments)
{
	/* Free the memory allocated for arguments */
	if (arguments != NULL)
	{
		for (int i = 0; arguments[i] != NULL; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
	}
}
