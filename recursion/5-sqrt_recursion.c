#include "main.h"

/**
 * find_sqrt - Recursively finds the square root of a number.
 * @n: The number to find the square root of.
 * @i: The current divisor to check.
 *
 * Return: The square root if found, otherwise -1.
 */
int find_sqrt(int n, int i)
{
	if (i * i == n) /* Base case: found the square root */
		return (i);
	if (i * i > n) /* If exceeded, return -1 */
		return (-1);
	return (find_sqrt(n, i + 1)); /* Try next number */
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The square root, or -1 if no natural square root exists.
 */
int _sqrt_recursion(int n)
{
	if (n < 0) /* Negative numbers do not have real square roots */
		return (-1);
	if (n == 0 || n == 1) /* Base cases: sqrt(0) = 0, sqrt(1) = 1 */
		return (n);
	return (find_sqrt(n, 1)); /* Start checking from 1 */
}
