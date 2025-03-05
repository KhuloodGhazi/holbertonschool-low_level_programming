#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to print.
 */
void _print_rev_recursion(char *s)
{
	if (*s) /* Base case: If s is not null */
	{
		_print_rev_recursion(s + 1); /* Recursive call moving forward */
		_putchar(*s); /* Print the character after recursion unwinds */
	}
}
