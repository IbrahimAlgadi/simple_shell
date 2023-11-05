#include "main.h"

/**
 * _strcat - concatenate two strings
 *
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 *
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
 *
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 *
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
 *
 * @s1: type str compared
 * @s2: type str compared
 *
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

/**
 * _strncmp - The function compares the first n characters of
 * two strings str1 and str2. It returns an integer less than,
 * equal to, or greater than zero if str1 is found, respectively,
 * to be less than, equal to, or greater than str2.
 *
 * @str1: str1
 * @str2: str2
 * @n: n
 *
 * Return: comp result.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}

	if (i == n)
	{
		return (0);
	} else if (str1[i] != '\0')
	{
		return (1);
	} else if (str2[i] != '\0')
	{
		return (-1);
	}

	return (0);
}

/**
 * cs_strlen - measure string length.
 *
 * @str: type str compared
 *
 * Return: length;
 */
size_t cs_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
