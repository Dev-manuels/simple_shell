#include "main.h"
static list_t *head_list;

/**
 * add_node - function that add new node at the beginning of a list
 * @str: string to be added to the list
 * @add: address of the string variable.
 * Return: address of the new element
 */
void *add_node(const char *str, char *add)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = _strdup(str);
	new_node->add = add;
	new_node->next = head_list;
	head_list = new_node;
	return (new_node);
}

/**
 * clear_env - atexit function for clearing mem-leaks
 */
void clear_env(void)
{
	if (head_list != NULL)
		free_list(head_list);
}

/**
 * free_node - function that deletes a node.
 * @name: node index to be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
*/
int free_node(const char *name)
{
	list_t *current, *prev;

	if (head_list != NULL)
	{
		prev = head_list;
		while (prev != NULL)
		{
			current = prev->next;
			if (_strcmp(name, current->str) == 0)
			{
				prev->next = current->next;
				free(current->add);
				free(current->str);
				free(current);
				current = NULL;
				return (0);
			}
			prev = prev->next;
		}
	}
	return (-1);
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
			free(temp->add);
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
 * Return: 0 on success, -1 on failure
*/
int _setenv(const char *name, const char *value)
{
	char *env, *token, *tmp;
	int count = 0, test = -1, size = _strlen(name) + _strlen(value) + 2;

	tmp = malloc(sizeof(char) * size);
	if (!tmp)
		return (-1);
	_strcpy(tmp, name);
	_strcat(tmp, "=");
	_strcat(tmp, value);

	while (environ[count])
	{
		env = _strdup(environ[count]);
		token = _strtok(env, "=");
		if (_strcmp(token, name) == 0)
		{
			environ[count] = _strdup(tmp);
			add_node(name, environ[count]);
			free(env);
			break;
		}
		if (_strcmp(token, name) != 0 && environ[count + 1] == NULL)
		{
			environ[count + 1] = _strdup(tmp);
			add_node(name, environ[count + 1]);
			environ[count + 2] = NULL;
			free(env);
			break;
		}
		count++;
		test = 1;
		free(env);
	}
	free(tmp);
	if (test == -1)
		write(STDERR_FILENO, "Set env failed\n", 16);
	return (count);
}
