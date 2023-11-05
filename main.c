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
	/* To suppress the warning for unused parameters */
	int gt_line;
	char *input;
	char **arguments;
	int true = 1;
	(void)argc;
	(void)argv;

	while (true)
	{
		write(STDIN_FILENO, "$ ", 2);
		input = read_user_input(&gt_line);

		if (gt_line != -1)
		{
			remove_newline(input);

			if (_strcmp(input, "exit") == 0)
			{
				break;
			}

			if (_strcmp(input, "env") == 0)
			{
				_print_env();
				continue;
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
