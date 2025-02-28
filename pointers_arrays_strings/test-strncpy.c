#include "main.h"
#include <stdio.h>

/**
 * main - Tests the _strncpy function
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[98]; /* Destination buffer */
	char *ptr;
	int i;

	/* Initialize s1 with '*' */
	for (i = 0; i < 98 - 1; i++)
	{
		s1[i] = '*';
	}
	s1[i] = '\0'; /* Null-terminate */

	printf("Before strncpy: %s\n", s1);

	/* Test copying first 5 characters */
	ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 5);
	printf("After strncpy (5 chars): %s\n", s1);
	printf("Pointer result: %s\n", ptr);

	/* Test copying the full string */
	ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 90);
	printf("After strncpy (90 chars): %s\n", s1);
	printf("Pointer result: %s\n", ptr);

	return (0);
}
