#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Test the print_dlistint function.
 *
 * Return: EXIT_SUCCESS on success.
 */
int main(void)
{
	dlistint_t node1, node2;
	dlistint_t *head;
	size_t count;

	/* Set up a small doubly linked list: node1 <-> node2 */
	node1.n = 8;
	node1.prev = NULL;
	node1.next = &node2;

	node2.n = 9;
	node2.prev = &node1;
	node2.next = NULL;

	head = &node1;

	/* Call the function and print the number of nodes */
	count = print_dlistint(head);
	printf("-> %lu nodes\n", count);

	return (EXIT_SUCCESS);
}

