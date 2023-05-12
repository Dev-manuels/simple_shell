#include "main.h"

char *_strtok(char *str, const char *delim)
{
	int index;
	static char *new_str = NULL;

	if (new_str == NULL && str == NULL)
	{
		return NULL;
	}

	if (str == NULL)
	{
		str = new_str;
	}

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == *delim)
		{
			while (str[index + 1] == *delim)
			{
				index++;
			}
			str[index] = '\0';
			new_str = &str[index + 1];
			break;
		}
	}

	if (str[index + 1] == '\0')
	{
		new_str = NULL;
	}

	return str;
}
