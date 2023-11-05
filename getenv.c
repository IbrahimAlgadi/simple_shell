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

	if (var == NULL || environ == NULL)
	{
		return NULL;
	}

	int i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], var, cs_strlen(var)) == 0 && environ[i][cs_strlen(var)] == '=')
		{
			return environ[i] + cs_strlen(var) + 1;
		}
		i++;
	}

	return NULL;
}
