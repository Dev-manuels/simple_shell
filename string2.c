#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert
 *
 * Return: An integer
 */
int _atoi(const char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}

		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}

		if (isi == 1)
		{
			break;
		}

		c++;
	}

	ni *= min;
	return (ni);
}

/**
* is_empty - Function that returns the length of a string
* @str: string to be read
* Return: 0 if empty, 1 if not
*/
int is_empty(const char *str)
{
	int i;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'))
			{
				return (1);
			}
		}
	} else
	{
		return (1);
	}

	return (0);
}

/**
 * get_path - function that gets the path to an
 * executeable program in the bin diretory by
 * concartinating cmd to /bin/
 * @cmd: the command to be executed
 * Return: pointer to the path on success, NULL
 * on failure
*/
char *get_path(char *cmd)
{
	char *path = NULL;
	char *prefix = "/bin/";
	int i, j = 0;

	if (access(cmd, X_OK | F_OK) == 0)
	{
		return (cmd);
	}
	if (cmd != NULL)
	{
		int size = _strlen(cmd) + _strlen(prefix) + 1;

		path = malloc(sizeof(char) * size);
		if (path != NULL)
		{
			for (i = 0; i < size - 1; i++)
			{
				if (i < _strlen(prefix))
				{
					path[i] = prefix[i];
				}
				else
				{
					path[i] = cmd[j];
					j++;
				}
			}
			free(cmd);
			path[i] = '\0';
			return (path);
		}
	}
	return (path);
}

/**
* _strcpy - copy the string pointed to by src to dest
* @dest: char to check
* @src: char to check
* Return: 0 is success
*/
char *_strcpy(char *dest, const char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, const char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
