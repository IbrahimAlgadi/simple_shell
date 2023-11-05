#include <stdio.h>

char *custom_strpbrk(const char *str, const char *chars)
{
	const char *s;
	const char *c;

	for (s = str; *s != '\0'; ++s)
	{
		for (c = chars; *c != '\0'; ++c)
		{
			if (*s == *c)
			{
				return (char *) s;
			}
		}
	}
	return NULL;
}

char *custom_strtok(char *str, const char *delim)
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
	token = custom_strpbrk(start, delim);

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

int main()
{
	char str[] = "this:issdsd:sada:asdasd";
	const char delimiters[] = ":";

	char *token = custom_strtok(str, delimiters);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = custom_strtok(NULL, delimiters);
	}

	return 0;
}