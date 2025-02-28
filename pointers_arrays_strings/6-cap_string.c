#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to modify
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";

	/* Capitalize first character if it's a lowercase letter */
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	/* Iterate through the string */
	for (i = 1; str[i] != '\0'; i++)
	{
		/* Check if the previous character is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i - 1] == separators[j] && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] -= 32; /* Convert lowercase to uppercase */
				break;
			}
		}
	}

	return (str);
}
