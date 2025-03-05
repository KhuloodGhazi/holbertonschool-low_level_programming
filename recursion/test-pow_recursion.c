#include "main.h"
#include <stdio.h>

/**
 * main - Test the _pow_recursion function.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = _pow_recursion(1, 10);
	printf("1^10 = %d\n", r); /* Expected: 1 */

	r = _pow_recursion(1024, 0);
	printf("1024^0 = %d\n", r); /* Expected: 1 */

	r = _pow_recursion(2, 16);
	printf("2^16 = %d\n", r); /* Expected: 65536 */

	r = _pow_recursion(5, 2);
	printf("5^2 = %d\n", r); /* Expected: 25 */

	r = _pow_recursion(5, -2);
	printf("5^-2 = %d\n", r); /* Expected: -1 (error) */

	r = _pow_recursion(-5, 3);
	printf("-5^3 = %d\n", r); /* Expected: -125 */

	return (0);
}
