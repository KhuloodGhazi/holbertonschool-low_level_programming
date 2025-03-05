#include "main.h"
#include <stdio.h>

/**
 * main - Test the is_prime_number function.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = is_prime_number(1);
	printf("is_prime_number(1) = %d\n", r); /* Expected: 0 */

	r = is_prime_number(1024);
	printf("is_prime_number(1024) = %d\n", r); /* Expected: 0 */

	r = is_prime_number(16);
	printf("is_prime_number(16) = %d\n", r); /* Expected: 0 */

	r = is_prime_number(17);
	printf("is_prime_number(17) = %d\n", r); /* Expected: 1 */

	r = is_prime_number(25);
	printf("is_prime_number(25) = %d\n", r); /* Expected: 0 */

	r = is_prime_number(-1);
	printf("is_prime_number(-1) = %d\n", r); /* Expected: 0 */

	r = is_prime_number(113);
	printf("is_prime_number(113) = %d\n", r); /* Expected: 1 */

	r = is_prime_number(7919);
	printf("is_prime_number(7919) = %d\n", r); /* Expected: 1 */

	return (0);
}
