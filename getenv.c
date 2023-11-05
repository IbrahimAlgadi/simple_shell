#include "main.h"

/**
 * _getenv - get environment variable value
 *
 * @var: env key
 *
 * Return: NULL or string
 */
char *_getenv(const char *var)
{
	int i = 0;

	if (var == NULL || environ == NULL)
	{
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		if (
			_strncmp(
				environ[i],
				var,
				cs_strlen(var)
			) == 0 && environ[i][cs_strlen(var)] == '=')
		{
			return (environ[i] + cs_strlen(var) + 1);
		}
		i++;
	}

	return (NULL);
}


/**
 * _print_env - prints the evironment variables
 *
 * Return: 1 on success.
 */
void _print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}
