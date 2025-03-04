#include "main.h"
#include <stdio.h>

/**
 * main - Test the _strpbrk function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello, world";
	char *f = "world";
	char *t;

	t = _strpbrk(s, f);
	printf("Result: %s\n", t); /* Expected output: "llo, world" */

	t = _strpbrk(s, "xyz");
	printf("Result: %s\n", t ? t : "NULL"); /* Expected output: NULL */

	return (0);
}
