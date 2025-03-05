#include "main.h"

/**
 * check_prime - Recursively checks if a number is prime.
 * @n: The number to check.
 * @i: The divisor to check against.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int check_prime(int n, int i)
{
	if (n <= 1) /* 0 and 1 are not prime */
		return (0);
	if (i * i > n) /* If no divisors were found, it is prime */
		return (1);
	if (n % i == 0) /* If n is divisible by i, it is not prime */
		return (0);
	return (check_prime(n, i + 1)); /* Try next divisor */
}

/**
 * is_prime_number - Determines if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (check_prime(n, 2)); /* Start checking from 2 */
}
