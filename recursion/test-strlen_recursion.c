#include "main.h"
#include <stdio.h>

/**
 * main - Test the _strlen_recursion function.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	n = _strlen_recursion("Holberton School");
	printf("Length: %d\n", n); /* Expected: 17 */

	n = _strlen_recursion("Recursion is powerful!");
	printf("Length: %d\n", n); /* Expected: 23 */

	n = _strlen_recursion("");
	printf("Length: %d\n", n); /* Expected: 0 */

	return (0);
}
