#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to encode
 *
 * Return: Pointer to the modified string
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char leet_codes[] = "4433007711";

	/* Iterate through the string */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* Check if the character is in letters[] */
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = leet_codes[j]; /* Replace with leet equivalent */
				break;
			}
		}
	}
	return (str);
}
