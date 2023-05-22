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
 * exit_status - Exit function with exit status
 * @input: exit status code/number
*/
void exit_status(const char *input)
{
	int status = _atoi(input);

	exit(status);
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
