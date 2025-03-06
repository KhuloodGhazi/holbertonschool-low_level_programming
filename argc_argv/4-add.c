#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - Checks if a string contains only digits.
 * @str: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i])) /* Check if character is not a digit */
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - Adds positive numbers.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 (Success), 1 (Error if non-digit character found).
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	/* If no number is passed, print 0 */
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	/* Iterate through all arguments */
	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i])) /* Check if argument is not a number */
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]); /* Convert string to integer and add */
	}

	/* Print the sum */
	printf("%d\n", sum);
	return (0);
}
