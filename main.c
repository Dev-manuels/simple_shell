#include "main.h"

/**
 * main - main program entry
 * Return: 0 on success, -1 on failure
*/
int main(void)
{
	int status = 0;

	atexit(clear_env);
	while (status == 0)
		status = prompt();

	return (0);
}

/**
 * chgdir - Function that changes the directory
 * of the calling process
 * @path: path to change to
*/
void chgdir(const char *path)
{
	char tmp[300];/* , *newpath; */

	getcwd(tmp, 300);
	printf("got here\n");
	if (path != NULL)
	{
		if (access(path, F_OK) == 0)
		{
			chdir(path);
			_setenv("OLDWD", tmp);
			_setenv("PWD", path);
		}
	}
}

/**
 * exe_bin - function that execute a binary program
 * @args: arguments to be passed to the program
 * Return: 0 on sucess, -1 on failure
*/
int exe_bin(char **args)
{
	if (access(args[0], X_OK | F_OK) == 0)
	{
		pid_t child = fork();

		if (child == -1)
			perror("./hsh");
		if (child != 0)
		{
			wait(NULL);
		} else
		{
			int val = execve(args[0], args, environ);

			if (val == -1)
				perror("./hsh");
			return (-1);
		}
	}

	return (0);
}

/**
 * freeWords - Function that dynamicaly frees an array of strings
 * @words: array of strings to be freed
 * @wordCount: number of words in the array
 * Return: 0 on success, -1 on failure
*/
int freeWords(char **words, int wordCount)
{
	int i;

	if (words != NULL && wordCount > 0)
	{
		for (i = 0; i <= wordCount; i++)
		{
			free((words)[i]);
		}
		free(words);
		return (0);
	}
	return (-1);
}

/**
 * _getenv - Function that returns an env value
 * @name: env value to be returned
 * Return: env value of name
*/
char *_getenv(const char *name)
{
	char *env, *delim = "=", *tmp;
	int i = 0;

	while (environ[i])
	{
		env = _strdup(environ[i]);
		tmp = _strtok(env, delim);
		if (strcmp(tmp, name) == 0)
		{
			tmp = _strtok(NULL, delim);
			free(env);
			return (tmp);
		}
		i++;
		free(env);
	}
	return (NULL);
}
