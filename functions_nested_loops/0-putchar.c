#include "main.h"

/**
 * main - Entry point
 *
 * Description: Prints "_putchar" followed by a new line
 * Return: 0 (Success)
 */
int main(void)
{
	char text[] = "_putchar";
	int i;

	for (i = 0; text[i] != '\0'; i++)
	{
		_putchar(text[i]);
	}
	_putchar('\n');

	return (0);
}
