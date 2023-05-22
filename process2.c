#include "main.h"
static list_t *head_list;

/**
 * add_node - function that add new node at the beginning of a list
 * @str: string to be added to the list
 * Return: address of the new element
 */
void *add_node(const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->next = head_list;
	head_list = new_node;
	return (new_node);
}

/**
 * clear_env - atexit function for clearing mem-leaks
*/
void clear_env(void)
{
	free_list(head_list);
}

/**
 * free_list - A function that frees all elements in a linked list
 * @head: pointer to head element of list
 * Return: Nothing
 */
void free_list(list_t *head)
{
	if (head != NULL)
	{
		list_t *temp;

		temp = head;
		while (head)
		{
			temp = head;
			head = head->next;
			_unsetenv(temp->str);
			free(temp->str);
			free(temp);
		}
		free(head);
	}
}

/**
 * _setenv - Function that sets an enviroment variable
 * @name: name of enviroment variable
 * @value: value of the enviroment variable
 * @overwrite: indicates if to overwrite existing
 * Return: 0 on success, -1 on failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	char *env, *token, *tmp;
	int count = 0;
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

/**
 * _unsetenv - Function that unsets an enviroment variable
 * @name: name of enviroment variable
 * Return: 0 on success, -1 on failure
*/
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
