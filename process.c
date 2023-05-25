#include "main.h"

static char **words;
static int wordCount;


/**
 * exe_cmd -  function that execute command
 * @args: array of arguments for the command
 * Return: 0 on sucess, -1 on failure
*/
int exe_cmd(char **args)
{
	int rtVal = 0;

	if (_strcmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(args[1]);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		chgdir(args[1]);
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		exit_status(args[1]);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2]);
	} else
	{
		args[0] = get_path(args[0]);
		rtVal = exe_bin(args);
	}
	return (rtVal);
}

/**
 * exit_status - Exit function with exit status
 * @input: exit status code/number
*/
void exit_status(const char *input)
{
	if (input != NULL)
	{
		int status = _atoi(input);

		if (words != NULL)
			freeWords(words, wordCount);
		exit(status);
	} else
	{
		if (words != NULL)
			freeWords(words, wordCount);
		exit(EXIT_SUCCESS);
	}
}

/**
 * prompt -  function that prompts the user for input
 * Return: 0 on success and -1 on failure
*/
int prompt(void)
{
	char *line = NULL;
	size_t line_size;
	ssize_t status_var;
	char *delim = " \n";
	int rtVal = -1, i = 0;

	if (isatty(STDIN_FILENO))
	{
		output("($) ");
		/* printf("Input is from terminal.\n"); */
	}
	status_var = getline(&line, &line_size, stdin);
	while (line[i] != '\n')
		i++;

	line[i] = '\0';
	/* Test that input was successful and exit if not */
	if (status_var > 0)
	{
		/* invoke the word separator function and get number of words read */
		wordCount = seperate_word(line, &words, i, delim);
		free(line);
		line = NULL;
	}
	rtVal = exe_cmd(words);
	if (words != NULL)
		freeWords(words, wordCount);
	return (rtVal);
}

/**
 * seperate_word - Function that seperates the words
 * in a string into a NULL terminated array of words
 * @line: The line of string to be operated
 * @words: Array to store the words
 * @line_size: size of the line string
 * @delim: Delimiter to be used for tokenization
 * Return: On success number of words tokenized, -1 on failure
*/
int seperate_word(char *line,
char ***words, int line_size, char *delim)
{
	int i;
	int wordCount = -1;
	char *token = NULL;


	if (line != NULL && _strcmp(line, "") != 0 && _strcmp(line, " ") != 0)
	{
		wordCount = 1;
		for (i = 0; i < line_size; i++)
		{
			if (line[i] == *delim)
			{
				if (line[i + 1] == '#')
					break;
				wordCount++;
			}
		}

		*words = (char **)malloc(sizeof(char *) * (wordCount + 1));
		if (*words != NULL)
		{
			token = _strtok(line, delim);

			i = 0;
			while (token != NULL)
			{
				(*words)[i] = _strdup(token);
				token = _strtok(NULL, delim);
				if (token != NULL)
				{
					if (token[0] == '#')
						token = NULL;
				}
				i++;
			}
			(*words)[i] = NULL;
		}
	}
	return (wordCount);
}

/**
 * _unsetenv - Function that unsets an enviroment variable
 * @name: name of enviroment variable
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	char *env, *token;
	int count = 0, test = -1;

	while (environ[count])
	{
		env = _strdup(environ[count]);

		token = _strtok(env, "=");
		if (_strcmp(token, name) == 0)
		{
			free_node(name);
			printf("got here\n");
			while (environ[count] != NULL)
			{
				environ[count] = environ[count + 1];
				count++;
			}
			environ[count] = NULL;
			free(env);
			test = 0;
			break;
		}
		count++;
		free(env);
		test = -1;
	}
	if (test == -1)
		write(STDERR_FILENO, "Unsetenv failed\n", 17);
	return (count);
}
