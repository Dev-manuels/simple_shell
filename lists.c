#include "main.h"

list_t *head_list;
/**
 * add_node - function that add new node at the beginning of a list
 * @head: pointer to the head
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

void clear_env(void)
{
	free_list(head_list);
}
