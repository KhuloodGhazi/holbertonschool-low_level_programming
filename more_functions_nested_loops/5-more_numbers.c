#include "main.h"

/**
 * more_numbers - Prints numbers from 0 to 14, ten times.
 */
void more_numbers(void)
{
	int i, num;
	char digits[] = "01234567891011121314\n";

	for (i = 0; i < 10; i++)
	{
		num = 0;
		while (digits[num] != '\0')
		{
			_putchar(digits[num]);
			num++;
		}
	}
}
