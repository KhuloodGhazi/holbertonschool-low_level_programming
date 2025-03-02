#include "main.h"
#include <stdio.h>

/**
 * main - Tests the _strchr function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello";
	char *f;

	f = _strchr(s, 'l'); /* Locate first occurrence of 'l' */

	if (f != NULL)
	{
		printf("Character found: %s\n", f);
	}
	else
	{
		printf("Character not found\n");
	}

	f = _strchr(s, 'z'); /* Locate 'z', which doesn't exist */

	if (f != NULL)
	{
		printf("Character found: %s\n", f);
	}
	else
	{
		printf("Character not found\n");
	}

	return (0);
}
