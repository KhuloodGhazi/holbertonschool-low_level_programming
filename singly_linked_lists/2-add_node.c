#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: pointer to the address of the head node of the list.
 * @str: string to be duplicated for the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	char *dup;
	unsigned int len = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (dup == NULL)
	{
		free(new);
		return (NULL);
	}
	while (str[len])
		len++;
	new->str = dup;
	new->len = len;
	new->next = *head;
	*head = new;
	return (new);
}
