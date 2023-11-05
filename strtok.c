#include "main.h"

/**
 * _strpbrk - This custom_strpbrk function mimics the
 * behavior of the standard strpbrk. It searches the
 * input string str for any character that matches
 * any character in the chars string.
 *
 * @str: str
 * @chars: chars
 *
 * Return: (char *) s or NULL
 */
char *_strpbrk(const char *str, const char *chars)
{
	const char *s;
	const char *c;

	for (s = str; *s != '\0'; ++s)
	{
		for (c = chars; *c != '\0'; ++c)
		{
			if (*s == *c)
			{
				return ((char *) s);
			}
		}
	}
	return NULL;
}

/**
 * _strtok - This custom_strtok function works
 * similarly to the standard strtok. It tokenizes
 * a string using a given set of delimiters.
 *
 * @str: str
 * @delim: delim
 *
 * Return: (char *) or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	if (str != NULL)
	{
		token = str;
	} else if (token == NULL)
	{
		return NULL;
	}

	char *start = token;
	token = _strpbrk(start, delim);

	if (token != NULL)
	{
		*token = '\0';
		token++;
	} else
	{
		token = NULL;
	}

	return start;
}
