#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string, or 0 if no numbers found.
 */
int _atoi(char *s)
{
	int sign = 1, result = 0, i = 0;
	
	/* Iterate through the string */
	while (s[i] != '\0')
	{
		/* Check for '-' or '+' to determine sign */
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9') /* Convert numeric characters */
		{
			/* Convert the digit and accumulate the result */
			result = (result * 10) + (s[i] - '0');

			/* Stop processing once a number sequence ends */
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;
	}

	return (result * sign);
}
