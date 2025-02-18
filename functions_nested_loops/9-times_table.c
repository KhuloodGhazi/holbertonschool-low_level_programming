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

			if (col == 0)
			{
				_putchar(product + '0'); /* First number, no comma */
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				/* Formatting for single-digit numbers */
				if (product < 10)
					_putchar(' ');

				_putchar((product / 10) + '0'); /* Tens digit */
				if (product >= 10)
					_putchar((product % 10) + '0'); /* Ones digit */
			}
		}
		_putchar('\n');
	}
}
