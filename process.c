#include "main.h"

/**
 * exe_cmd -  function that execute command
 * @argv: array of arguments to be passed to execve
 * Return: 0 on sucess, -1 on failure
*/
int exe_cmd(char **argv)
{
	pid_t child = fork();

	if (child == -1)
		perror("fork failed");
	if (child != 0)
	{
		wait(NULL);
	} else
	{
		int val = execve(argv[0], argv, NULL);

		if (val == -1)
			perror("./hsh");
		return (-1);
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

	if (words != NULL && wordCount > 0)
	{
		for (i = 0; i <= wordCount; i++)
		{
			free((*words)[i]);
		}
		free(*words);
		return (0);
	}
	return (-1);
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
		return (cmd);
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
			path[i] = '\0';
			return (path);
		}
	}
	return (path);
}

/**
 * prompt -  function that prompts the user for input
 * Return: 0 on success and -1 on failure
*/
int prompt(void)
{
	char *line = NULL, *line_copy = NULL;
	size_t line_size = 0;
	ssize_t status_var;
	char *delim = " \n";
	char **words = NULL;
	int wordCount = 0, rtVal = -1;

	output("($) ");
	status_var = getline(&line, &line_size, stdin);

	line_copy = malloc(line_size);
	/* Test that input was successful and exit if not */
	if (status_var > 0 && line_copy != NULL)
	{
		/* invoke the word separator function and get number of words read */
		wordCount = seperate_word(line, line_copy, &words, line_size, delim);
		rtVal = 0;
	}
	exe_cmd(words);
	freeWords(&words, wordCount);
	free(line);
	free(line_copy);
	return (rtVal);
}

/**
 * seperate_word - Function that seperates the words
 * in a string into a NULL terminated array of words
 * @line: The line of string to be operated
 * @line_copy: Stored the duplicate of line for tokenization
 * @words: Array to store the words
 * @line_size: size of the line string
 * @delim: Delimiter to be used for tokenization
 * Return: On success number of words tokenized, -1 on failure
*/
int seperate_word(char *line, char *line_copy,
char ***words, size_t line_size, char *delim)
{
	size_t i;
	int wordCount = 0;
	char *token = NULL;


	if (line != NULL && _strcmp(line, "") != 0 && _strcmp(line, " ") != 0)
	{
		wordCount = 1;
		for (i = 0; i < line_size; i++)
		{
			if (line[i] == *delim)
			{
				wordCount++;
			}
			line_copy[i] = line[i];
		}

		*words = (char **)malloc(sizeof(char *) * (wordCount + 1));
		if (*words != NULL)
		{
			token = get_path(strtok(line_copy, delim));

			i = 0;
			while (token != NULL)
			{
				(*words)[i] = _strdup(token);
				if (i < 1)
					free(token);
				token = strtok(NULL, delim);
				printf("%s\n", (*words)[i]);
				i++;
			}
			(*words)[i] = NULL;
		}
		return (wordCount);
	}
	return (-1);
}

