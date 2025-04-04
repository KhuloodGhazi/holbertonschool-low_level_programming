#include "main.h"

/**
 * flip_bits - Returns the number of bits you would need to flip to
 *	get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits required to flip, or 0 if n equals m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	unsigned int count;

	diff = n ^ m;
	count = 0;
	while (diff)
	{
		diff &= (diff - 1);
		count++;
	}
	return (count);
}
