#include "main.h"
#include <stdio.h>

/**
 * main - Tests the string_toupper function
 *
 * Return: Always 0
 */
int main(void)
{
	char str[] = "Hello, Holberton! Look up!\n";
	char *ptr;

	printf("Before: %s", str);
	ptr = string_toupper(str);
	printf("After: %s", ptr);

	return (0);
}
