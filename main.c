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
 * _strlen - calculate the length of a string.
 *
 * @s: the string to calculate it's length.
 * Return: length of a string.
 */

int _strlen(char *s)
{
	int i;
	int length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}


/**
 * remove_newline - removes \n from string
 *
 * @str: string
 *
 * Return: Noting
 */
void remove_newline(char *str)
{
	int length = _strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break; // Assuming there's only one newline, so we stop after the first occurrence
		}
	}
}


void execute_command(char **command_and_arguments)
{
	pid_t child_pid = fork();  // Fork a child process

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		// Child process
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);  // If exec fails, exit child process
		}
	} else
	{
		// Parent process waits for the child to finish
		wait(NULL);
	}
}


void free_arguments(char **arguments)
{
	// Free the memory allocated for arguments
	if (arguments != NULL)
	{
		for (int i = 0; arguments[i] != NULL; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
	}
}

/**
 * main - Simple Shell
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
			arguments = strtow(input);
			execute_command(arguments);
		}

		free(input);
		/* Free the memory allocated for arguments */
		free_arguments(arguments);
	}
	return 0;
}

