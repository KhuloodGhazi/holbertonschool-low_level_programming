#include "main.h"

/**
 * string_toupper - Converts all lowercase letters in a string to uppercase
 * @str: The string to modify
 *
 * Return: The modified string
 */
char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32; /* Convert to uppercase by subtracting ASCII difference */
	}

	return (str);
}
