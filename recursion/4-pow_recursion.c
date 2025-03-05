#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: Base number.
 * @y: Exponent.
 *
 * Return: x raised to the power y, or -1 if y is negative.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0) /* Error case */
		return (-1);
	if (y == 0) /* Base case: x^0 = 1 */
		return (1);
	return (x * _pow_recursion(x, y - 1)); /* Recursive case */
}
