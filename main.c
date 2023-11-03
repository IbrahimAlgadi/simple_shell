#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_user_input(int *gt_line)
{
	char *input = NULL;
	size_t bufsize = 0;

	*gt_line = getline(&input, &bufsize, stdin);

	return (input);
}


/**
 * main - Simple Shell
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int gt_line;
	char *input;
	char** argv;

	while (1) {

		write(STDIN_FILENO, "$ ", 2);
		input = read_user_input(&gt_line);

		if (gt_line != -1)
		{
			printf("%s", input);
			argv = strtow(input);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}

	}
}

