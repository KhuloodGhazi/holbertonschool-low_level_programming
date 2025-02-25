#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1, or -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
