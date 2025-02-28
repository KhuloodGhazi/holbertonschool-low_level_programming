#include "main.h"
#include <stdio.h>

/**
 * main - Tests the cap_string function
 *
 * Return: Always 0
 */
int main(void)
{
	char str[] = "hello world! welcome to coding. let's capitalize.";
	char *ptr;

	printf("Before: %s\n", str);
	ptr = cap_string(str);
	printf("After: %s\n", ptr);

	return (0);
}
