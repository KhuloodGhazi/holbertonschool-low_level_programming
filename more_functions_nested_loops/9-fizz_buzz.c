#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with Fizz, Buzz, and FizzBuzz.
 *
 * Description: For multiples of 3, print "Fizz" instead of the number.
 * For multiples of 5, print "Buzz". For multiples of both, print "FizzBuzz".
 * Each number or word is separated by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3 == 0)
		    && (i % 5 == 0))
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%d", i);
		}

		if (i < 100)
		{
			printf(" ");
		}
	}
	printf("\n");

	return (0);
}
