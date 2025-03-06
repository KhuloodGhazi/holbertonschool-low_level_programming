#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 (Success), 1 (Error if incorrect number of arguments).
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	/* Check if exactly two numbers were provided */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert arguments to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	/* Multiply and print result */
	result = num1 * num2;
	printf("%d\n", result);

	return (0);
}
