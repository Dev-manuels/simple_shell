#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env, *token, *tmp;
	int count = 0, i = 0, j = 0;
	int size = _strlen(name) + _strlen(value) + 2;

	tmp = malloc(sizeof(char) * size);
	if (!tmp)
	{
		return (-1);
	}
	_strcpy(tmp, name);
	_strcat(tmp, "=");
	_strcat(tmp, value);

	while (environ[count])
	{
		env = _strdup(environ[count]);

		token = strtok(env, "=");
		if (_strcmp(token, name) == 0 && overwrite != 0)
		{
			environ[count] = _strdup(tmp);
			add_node(name);
			free(env);
			break;
		}
		if (_strcmp(token, name) != 0 && environ[count + 1] == NULL)
		{
			environ[count + 1] = _strdup(tmp);
			add_node(name);
			environ[count + 2] = NULL;
			free(env);
			break;
		}
		count++;
		free(env);
	}
	free(tmp);
	return (count);
}

int main()
{
	int count = _setenv("SHELL", "bash", 1);
	printf("%d\n", count);
	count = 0;

	atexit(clear_env);
	while (environ[count])
	{
		printf("count: %d = %s\n", count, environ[count]);
		count++;
	}

	return 0;
}
