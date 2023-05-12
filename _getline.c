#include "main.h"

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
