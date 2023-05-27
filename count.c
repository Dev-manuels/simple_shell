#include "main.h"

/**
 * count_words - function that count words in string
 * @string: string with words
 * Return: count of words
*/
int count_words(char *string)
{
	int word_count = 0, i = 0;
	char delimiter = ' ';

	while (string[i] != '\0')
	{
		if (string[i] != delimiter)
		{
			word_count++;
			while (string[i] != '\0' && string[i] != delimiter)
			{
				if (string[i + 1] == delimiter)
				{
				i++;
				continue;
				}
				i++;
			}
		} else
		{
			i++;
		}
	}

	if (string[i - 1] == delimiter)
		word_count--;

	return (word_count);
}
