#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line.
 * @str: Pointer to the string.
 */
void puts_half(char *str)
{
	int length = 0, n, i;

	/* Find the length of the string */
	while (str[length] != '\0')
	{
		length++;
	}

	/* Calculate the starting index for the second half */
	if (length % 2 == 0)
		n = length / 2;
	else
		n = (length + 1) / 2;

	/* Print the second half of the string */
	for (i = n; i < length; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
