#include "main.h"

/**
 * execute_command - Executes command arguments passed
 * from the main function
 *
 * @command_and_arguments: the memory allocated for input string
 * passed by the shell user contain the command and the arguments
 * of the command
 *
 * Return: Always 0
 */
void execute_command(char **command_and_arguments)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		/* Child process */
		if (execve(command_and_arguments[0], command_and_arguments, NULL) == -1)
		{
			perror("Error");
			/* If exec fails, exit child process */
			exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process waits for the child to finish */
		wait(NULL);
	}
}
