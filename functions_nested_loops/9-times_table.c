#include "main.h"

/**
 * times_table - Prints the 9 times table from 0.
 */
void times_table(void)
{
	int row, col, product;

	for (row = 0; row <= 9; row++)
	{
		for (col = 0; col <= 9; col++)
		{
			product = row * col;

			/* Print first number without a comma */
			if (col == 0)
			{
				_putchar(product + '0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				/* Ensure correct spacing for alignment */
				if (product < 10)
					_putchar(' ');

				/* Print tens and ones digits properly */
				if (product >= 10)
					_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
