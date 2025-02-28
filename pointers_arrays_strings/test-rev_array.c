#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @a: The array to print
 * @n: The number of elements in the array
 *
 * Return: Nothing (void)
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

/**
 * main - Test the reverse_array function
 *
 * Return: Always 0.
 */
int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Original array:\n");
	print_array(a, 10);

	reverse_array(a, 10);

	printf("Reversed array:\n");
	print_array(a, 10);

	return (0);
}
