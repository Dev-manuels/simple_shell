#include "main.h"

/**
 * _getline - Custom getline function
 * @buffer: buffer to store the input
 * @bufsize: Stores the size of the buffer
 * @stream: input stream
 * Return: count of chars inputed
*/
size_t _getline(char **buffer, size_t *bufsize, FILE *stream)
{
	size_t count;
	char *c;

	c = malloc(*bufsize * sizeof(buffer));

	if (c == NULL)
	{
		return (0);
	}

	for (count = 0; c[count] != '\n'; count++)
	{
		c[count] = getc(stream);
		if (count > *bufsize)
		{
			*bufsize = count;
			c = realloc(c, *bufsize);
		}
		*buffer = c;
	}
	*buffer[count] = '\0';
	free(c);

	return (count);
}
