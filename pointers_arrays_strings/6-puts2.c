#include "main.h"
#include <stddef.h>  /* To define NULL */

/**
 * puts2 - Prints every other character of a string.
 * @str: Pointer to the string.
 */
void puts2(char *str)
{
	int i;

	if (str == NULL) /* Edge case: NULL input */
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0) /* Print only even indices */
			_putchar(str[i]);
	}
	_putchar('\n');
}
