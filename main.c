#include "main.h"

/**
 * main - Simple Shell
 *
 * @argc: counter
 * @argv: arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int TRUE;
	int gt_line;
	char *input;
	char **arguments;

	TRUE = 1;
	while (TRUE)
	{
		write(STDIN_FILENO, "$ ", 2);
		input = read_user_input(&gt_line);

		if (gt_line != -1)
		{
			remove_newline(input);

			if (_strcmp(input, &'exit')) {
				break;
			}

			arguments = strtow(input);
			execute_command(arguments);
		}

		free(input);
		/* Free the memory allocated for arguments */
		free_arguments(arguments);
	}
	return (0);
}
