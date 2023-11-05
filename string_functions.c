#include "main.h"

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
 * _strchr - It searches for a specific character
 * within a given string and returns a pointer to
 * the first occurrence of the character.
 *
 * @str: string
 * @character: character
 *
 * Return: Return NULL if not found
 */
char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *) str);
		}
		str++;
	}

	return (NULL);
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
			break;
		}
	}
}
