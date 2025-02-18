#include "main.h"

/**
 * jack_bauer - Prints every minute of the day from 00:00 to 23:59.
 */
void jack_bauer(void)
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			_putchar((hour / 10) + '0');  /* Prints the first digit of the hour */
			_putchar((hour % 10) + '0');  /* Prints the second digit of the hour */
			_putchar(':');
			_putchar((minute / 10) + '0'); /* Prints the first digit of the minute */
			_putchar((minute % 10) + '0'); /* Prints the second digit of the minute */
			_putchar('\n');
		}
	}
}
