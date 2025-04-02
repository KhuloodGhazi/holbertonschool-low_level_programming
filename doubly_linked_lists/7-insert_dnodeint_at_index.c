#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the head of the dlistint_t list.
 * @idx: Index at which the new node should be inserted (starts at 0).
 * @n: Integer to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed or if the index
 *         is out of range.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	/* Traverse to the node at index (idx - 1) */
	for (i = 0; current != NULL && i < idx - 1; i++)
		current = current->next;
	if (current == NULL)
		return (NULL);

	/* If inserting at the end, current->next will be NULL */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
