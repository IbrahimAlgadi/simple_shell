#include "main.h"

/**
 * count_total_words - Count total words in sentence
 * @s: input string sentence
 *
 * Return: number of words
 */
int count_total_words(char *s)
{
	int i, count = 0;
	int in_word = 0;

	/* Iterate through each character in the sentence */
	for (i = 0; s[i] != '\0'; i++)
	{
		/*
		 * If the current character is a space or a
		 * newline, we're not in a word
		 *
		 */
		if (s[i] == ' ' || s[i] == '\n')
		{
			in_word = 0;
		}
			/*
			 *
			 * If the current character is not a space or
			 * newline, and we're not in a word,
			 * increment the word count
			 *
			 */
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
	}

	return (count);
}


/**
 * copy_to_memory - Copy word from string to memory
 * @str: origional string
 * @word_letters: Word Total Letter Count
 * @start: Start word index
 * @end: End word index
 * Return: number of words
 */
char *copy_to_memory(char *str, int word_letters, int start, int end)
{
	char *word_memory;
	int i;

	/*printf("String: %s\n", str);*/
	/*printf("Word Letters: %d\n", word_letters);*/
	/* Allocate memory equal to the size of letter plus '\0' */
	word_memory = (char *) malloc(sizeof(char) * (word_letters + 1));
	if (word_memory == NULL)
		return (NULL);
	/*
	 * Copy letter from string to
	 * the allocated memory locations
	 * from start of word index to end of word index
	 */
	i = 0;
	while (start < end)
	{
		/*printf("start: %d - end: %d\n", start, end);*/
		*(word_memory + i) = str[start];
		/*printf("%c", *(word_memory+i));*/
		start++;
		i++;
	}
	/* printf("\n"); */
	*(word_memory + i) = '\0';
	return (word_memory);
}

/**
 * **strtow - Write a function that splits a string into words.
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **string_matrix;
	int i, k = 0, len = 0, total_words, word_letters = 0, start, end;

	while (*(str + len))
		len++;
	total_words = count_total_words(str);
	/* printf("Total Words: %d\n", total_words); */
	if (total_words == 0)
		return (NULL);

	string_matrix = (char **) malloc(sizeof(char *) * (total_words + 1));
	if (string_matrix == NULL)
		return (NULL);

	/* Loop Over Total Number Of Letter In The String */
	for (i = 0; i <= len; i++)
	{
		/* If The Current Is Space Or End Of The String Then */
		if (str[i] == ' ' || str[i] == '\0')
		{
			/* Check if we have counted word letters */
			if (word_letters)
			{
				end = i;
				string_matrix[k] = copy_to_memory(str, word_letters, start, end);
				/* If the allocation has error then return NULL */
				if (string_matrix[k] == NULL)
					return (NULL);
				k++;
				/* Reset Word Letters Count */
				word_letters = 0;
			}
		} else if (word_letters++ == 0)
			start = i;
	}

	/* Set the last memory location to NULL */
	string_matrix[k] = NULL;

	return (string_matrix);
}
