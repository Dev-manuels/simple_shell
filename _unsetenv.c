#include "main.h"

int _unsetenv(const char *name)
{
	char *env, *token;
	int count = 0;

	while (environ[count])
	{
		env = _strdup(environ[count]);

		token = strtok(env, "=");
		if (_strcmp(token, name) == 0)
		{
			free(environ[count]);
			while (environ[count] != NULL)
			{
				environ[count] = environ[count + 1];
				count++;
			}
			environ[count] = NULL;
			free(env);
			break;
		}
		count++;
		free(env);
	}
	return (count);
}
