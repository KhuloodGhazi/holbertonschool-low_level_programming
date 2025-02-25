#include "main.h"

/**
 * print_numbers - Prints the numbers from 0 to 9, followed by a new line.
 */
void print_numbers(void)
{
	char num[] = "0123456789\n";
	int i;

	for (i = 0; num[i] != '\0'; i++)
		_putchar(num[i]);
}
