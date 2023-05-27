#include "main.h"

/**
 * _strdup - function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of
 * the string given as a parameter.
 * @str: string to be copied
 * Return: copy of the string passed.
*/
char *_strdup(const char *str)
{
	char *s;

	if (str == NULL)
	{
		s = NULL;
	} else
	{
		int size = _strlen(str);
		int i;

		s = malloc(sizeof(char) * size + 1);
		if (s != NULL)
		{
			for (i = 0; i <= size; i++)
			{
				s[i] = str[i];
			}
		}
	}
	return (s);
}

/**
 * _strcmp - custom string compare function
 * @s1: string 1
 * @s2: string 2
 * Return: returns the difference between
 * mismatched characters, 0 if none
*/
int _strcmp(const char *s1, const char *s2)
{
	if (s1 != NULL || s2 != NULL)
	{
		while (*s1 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}

	return (-1);
}

/**
* _strlen - Function that returns the length of a string
*
* @s: string to be read
* Return: int
*/
int _strlen(const char *s)
{
	int len = 0;

	if (s != NULL)
	{
		while (s[len] != '\0')
			len++;
	}

	return (len);
}

/**
 * _strtok - Custom _strtok function that
 * tokenizes a string
 * @str: String to be tokenized
 * @delim: Delimiter character
 * Return: Pointer token
*/
char *_strtok(char *str, const char *delim)
{
	static char *t, *s;
	unsigned int a;

	if (str != NULL)
		s = str;
	t = s;
	if (t == NULL)
		return (NULL);
	for (a = 0; t[a] != '\0'; a++)
	{
		if (check_delim(t[a], delim) == 0)
			break;
	}
	if (s[a] == '\0' || s[a] == '#')
	{
		s = NULL;
		return (NULL);
	}
	t = s + a;
	s = t;
	for (a = 0; s[a] != '\0'; a++)
	{
		if (check_delim(s[a], delim) == 1)
			break;
	}
	if (s[a] == '\0')
		s = NULL;
	else
	{
		s[a] = '\0';
		s = s + a + 1;

		if (*s == '\0')
			s = NULL;
	}
	return (t);
}

/**
 * output -  function that prints out a string
 * @s: string to be printed out
 * Return: length of char printed on success,
 * -1 on failure
*/
int output(const char *s)
{
	int count = -1;

	if (s != NULL)
	{
		count = write(1, s, _strlen(s));
	}
	return (count);
}
