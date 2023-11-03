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
 * remove_newline - removes \n from string
 *
 * @str: string
 *
 * Return: Noting
 */
void remove_newline(char *str) {
	int length = strlen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
			break; // Assuming there's only one newline, so we stop after the first occurrence
		}
	}
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
	char **arguments;

	while (1) {

		write(STDIN_FILENO, "$ ", 2);
		input = read_user_input(&gt_line);

		if (gt_line != -1)
		{
			printf("%s", input);
			remove_newline(input);
			arguments = strtow(input);
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror("Error:");
			}
		}

	}
}

