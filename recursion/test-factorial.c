#include "main.h"
#include <stdio.h>

/**
 * main - Test the factorial function.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = factorial(0);
	printf("Factorial of 0: %d\n", r); /* Expected: 1 */

	r = factorial(1);
	printf("Factorial of 1: %d\n", r); /* Expected: 1 */

	r = factorial(5);
	printf("Factorial of 5: %d\n", r); /* Expected: 120 */

	r = factorial(10);
	printf("Factorial of 10: %d\n", r); /* Expected: 3628800 */

	r = factorial(-1024);
	printf("Factorial of -1024: %d\n", r); /* Expected: -1 (error) */

	return (0);
}
