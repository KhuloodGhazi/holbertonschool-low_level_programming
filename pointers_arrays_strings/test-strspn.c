#include "main.h"
#include <stdio.h>

/**
 * main - Tests the _strspn function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello, world";
	char *f = "oleh";
	unsigned int n;
	/* Declare all variables at the beginning */
	char *s2 = "abcdef12345";
	char *f2 = "abcde";
	char *s3 = "123456";
	char *f3 = "abc";


	n = _strspn(s, f);
	printf("Length of prefix substring: %u\n", n);
	n = _strspn(s2, f2);
	printf("Length of prefix substring: %u\n", n);
	n = _strspn(s3, f3);
	printf("Length of prefix substring: %u\n", n); /* Expect 0 */
	return (0);
}
