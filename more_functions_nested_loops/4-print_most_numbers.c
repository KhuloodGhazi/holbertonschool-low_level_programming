#include "main.h"

/**
 * print_most_numbers - Prints the numbers from 0 to 9,
 *                     excluding 2 and 4, followed by a new line.
 */
void print_most_numbers(void)
{
	char num[] = "01356789\n";
	int i;

	for (i = 0; num[i] != '\0'; i++)
		_putchar(num[i]);
}
