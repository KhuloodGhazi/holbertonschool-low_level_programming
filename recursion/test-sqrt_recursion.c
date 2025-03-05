#include "main.h"
#include <stdio.h>

/**
 * main - Test the _sqrt_recursion function.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = _sqrt_recursion(1);
	printf("sqrt(1) = %d\n", r); /* Expected: 1 */

	r = _sqrt_recursion(1024);
	printf("sqrt(1024) = %d\n", r); /* Expected: 32 */

	r = _sqrt_recursion(16);
	printf("sqrt(16) = %d\n", r); /* Expected: 4 */

	r = _sqrt_recursion(17);
	printf("sqrt(17) = %d\n", r); /* Expected: -1 (not a perfect square) */

	r = _sqrt_recursion(25);
	printf("sqrt(25) = %d\n", r); /* Expected: 5 */

	r = _sqrt_recursion(-1);
	printf("sqrt(-1) = %d\n", r); /* Expected: -1 (error) */

	return (0);
}
