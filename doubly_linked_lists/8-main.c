#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * run_deletion_tests - Runs a series of deletion tests on a dlistint_t list.
 * @head: Pointer to the pointer to the head of the list.
 */
void run_deletion_tests(dlistint_t **head)
{
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 5);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	printf("-----------------\n");
	delete_dnodeint_at_index(head, 0);
	print_dlistint(*head);
}

/**
 * main - Entry point for testing deletion of nodes in a doubly linked list.
 *
 * Return: Always 0.
 */
int main(void)
{
	dlistint_t *head;

	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	print_dlistint(head);
	run_deletion_tests(&head);
	return (0);
}
