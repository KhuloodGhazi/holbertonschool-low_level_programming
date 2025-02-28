#include "main.h"
#include <stdio.h>

/**
 * main - Tests the leet function
 *
 * Return: Always 0
 */
int main(void)
{
	char str[] = "Leet coding is so cool!";
	char *ptr;

	printf("Before: %s\n", str);
	ptr = leet(str);
	printf("After: %s\n", ptr);

	return (0);
}
