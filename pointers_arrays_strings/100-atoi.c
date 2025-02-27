#include "main.h"
#include <limits.h>  /* Include to use INT_MAX and INT_MIN */

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string, or 0 if no numbers found.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int result = 0;

	/* Traverse string */
	while (s[i] != '\0')
	{
		/* Update sign if we encounter '-' */
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9') /* Convert number */
		{
			/* Multiply by 10 and add digit */
			result = (result * 10) + (s[i] - '0');

			/* Handle integer overflow */
			if (result > INT_MAX)
				return (sign == 1 ? INT_MAX : INT_MIN);

			/* Stop processing once numbers end */
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;
	}

	return (sign * result);
}
