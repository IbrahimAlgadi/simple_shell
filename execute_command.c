#include "main.h"


/**
 * _find_command - locates a command
 *
 * @cmd: command name
 *
 * Return: location of the command or the command.
 */
char *_find_command(char *cmd)
{
	char *path, *selected_path, *command_dir;
	int path_length, command_length;

	path = _getenv("PATH");

	if (path != NULL)
	{
		command_length = _strlen(cmd);
		selected_path = _strtok(path, ":");
		path_length = _strlen(selected_path);
		while (selected_path != NULL)
		{
			path_length = _strlen(selected_path);
			command_dir = malloc(path_length + command_length + 2);
			/* copy selected path to the allocated memory */
			_strcpy(command_dir, selected_path);
			/* add / to the selected memory */
			_strcat(command_dir, "/");
			/* after slash add the passed command */
			_strcat(command_dir, cmd);
			/* end the string of the allocated memory */
			_strcat(command_dir, "\0");
			/* search if the command file exists in the path */
			if (access(command_dir, X_OK) != -1)
			{
				return (command_dir);
			}
			free(command_dir);
			selected_path = _strtok(NULL, ":");
		}
	}

	return (cmd);

}

/**
 * execute_command - Executes command arguments passed
 * from the main function
 *
 * @command_and_arguments: the memory allocated for input string
 * passed by the shell user contain the command and the arguments
 * of the command.
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
		/*
		 * if command is sent with the
		 * path attached to it just execute it
		 * else search for the command path if found
		 */
		if (execve(
			_find_command(command_and_arguments[0]),
			command_and_arguments,
			environ
		) == -1)
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
