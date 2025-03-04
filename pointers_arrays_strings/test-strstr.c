#include "main.h"
#include <stdio.h>

/**
 * main - Test the _strstr function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello, world";
	char *f = "world";
	char *t;

	t = _strstr(s, f);
	printf("Result: %s\n", t); /* Expected output: "world" */

	t = _strstr(s, "hello");
	printf("Result: %s\n", t); /* Expected output: "hello, world" */

	t = _strstr(s, "xyz");
	printf("Result: %s\n", t ? t : "NULL"); /* Expected output: NULL */

	return (0);
}
