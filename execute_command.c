#include "main.h"


/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

int _strncmp(const char *str1, const char *str2, size_t n) {
	size_t i;
	for (i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}

	if (i == n) {
		return 0; // Both strings are equal up to n characters
	} else if (str1[i] != '\0') {
		return 1; // str1 is longer
	} else if (str2[i] != '\0') {
		return -1; // str2 is longer
	}

	return 0;
}

size_t cs_strlen(const char *str) {
	size_t length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

char *_getenv(const char* var) {
	extern char **environ;

	if (var == NULL || environ == NULL) {
		return NULL;
	}

	int i = 0;
	while (environ[i] != NULL) {
		if (_strncmp(environ[i], var, cs_strlen(var)) == 0 && environ[i][cs_strlen(var)] == '=') {
			return environ[i] + cs_strlen(var) + 1;
		}
		i++;
	}

	return NULL;
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}


/**
 * _which - locates a command
 *
 * @cmd: command name
 *
 * Return: location of the command.
 */
char *_find_command(char *cmd)
{
	char *path, *selected_path, *command_dir;
	int path_length, command_length;
	struct stat file_stats;

	path = _getenv("PATH");
	fprintf(stdout, "path: %s\n", path);

	command_length = _strlen(cmd);
	fprintf(stdout,"command_length: %d\n", command_length);
	selected_path = strtok(path, ":");
	path_length = _strlen(selected_path);
	fprintf(stdout,"path_length: %d\n", path_length);
	while (selected_path != NULL)
	{
		fprintf(stdout,"selected_path: %s\n", selected_path);
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
		if (stat(command_dir, &file_stats) == 0)
		{
			free(path);
			fprintf(stdout,"found command: %s\n", command_dir);
			return (command_dir);
		}
		free(command_dir);
		selected_path = strtok(NULL, ":");
	}
	fprintf(stdout,"selected_path: %s\n", selected_path);
	free(path);
	if (stat(cmd, &file_stats) == 0)
		return (cmd);
	return (NULL);

}


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
void execute_command(char **command_and_arguments, char **env)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		/* Child process */
		/* if command is sent with the
		 * path attached to it just execute it
		 * else search for the command path if found
		 * */
		if (execve(_find_command(command_and_arguments[0]), command_and_arguments, env) == -1)
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
