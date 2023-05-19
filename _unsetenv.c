#include "main.h"

int _unsetenv(const char *name)
{
	char *env, *token;
	int count = 0;

	while (environ[count])
	{
		env = strdup(environ[count]);

		token = strtok(env, "=");
		if (strcmp(token, name) == 0)
		{
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

int main()
{
	int count = _unsetenv("GROUP");
	count = 0;
	while (environ[count])
	{
		printf("%s\n", environ[count]);
		count++;
	}

	return 0;
}
