#include "main.h"

/**
 * check_delim - function that validate delim string
 * @s: pointer to character to check
 * @st: pointer to thr string of delim
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char s, const char *st)
{
	unsigned int a;

	for (a = 0; st[a] != '\0'; a++)
	{
		if (s == st[a])
			return (1);
	}
	return (0);
}

/**
 * chgdir - Function that changes the directory
 * of the calling process
 * @path: path to change to
*/
void chgdir(char *path)
{
	char tmp[600], *newpath = path;

	getcwd(tmp, 600);
	if (path != NULL)
	{
		if (_strcmp(path, "-") == 0)
		{
			newpath = _getenv("OLDWD");
		}
		if (newpath != NULL)
		{
			if (access(newpath, F_OK) == 0)
			{
				chdir(newpath);
				_setenv("OLDWD", tmp);
				_setenv("PWD", newpath);
			}
		}
	} else
	{
		newpath = _getenv("HOME");
		if (newpath != NULL)
		{
			if (access(newpath, F_OK) == 0)
			{
				chdir(newpath);
				_setenv("OLDWD", tmp);
				_setenv("PWD", newpath);
			}
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
	} else
	{
		errno = ENOENT;
		perror("./hsh");
		return (2);
	}
	return (0);
}

/**
 * freeWords - Function that dynamicaly frees an array of strings
 * @words: array of strings to be freed
 * @wordCount: number of words in the array
 * Return: 0 on success, -1 on failure
*/
int freeWords(char ***words, int wordCount)
{
	int i;

	if (*words != NULL && wordCount > 0)
	{
		for (i = 0; i <= wordCount; i++)
		{
			if ((*words)[i] != NULL)
			{
				free((*words)[i]);
				(*words)[i] = NULL;
			}
		}
		if (*words != NULL)
		{
			free(*words);
			*words = NULL;
		}
		wordCount = 0;
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
	int i = 0, j = 0;

	while (environ[i])
	{
		env = _strdup(environ[i]);
		tmp = _strtok(env, delim);
		if (_strcmp(tmp, name) == 0)
		{
			tmp = _strtok(NULL, delim);
			free(env);
			while ((environ[i])[j] != '=')
			{
				j++;
			}
			j++;
			tmp = &(environ[i])[j];
			return (tmp);
		}
		i++;
		free(env);
	}
	return (NULL);
}
