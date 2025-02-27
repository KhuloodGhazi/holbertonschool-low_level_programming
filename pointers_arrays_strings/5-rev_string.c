#include "main.h"

/**
 * rev_string - Reverses a string in place.
 * @s: Pointer to the string to be reversed.
 */
void rev_string(char *s)
{
	int length = 0, i;
	char temp;

	/* Find the length of the string */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Swap characters from start to end */
	for (i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[length - i - 1];
		s[length - i - 1] = temp;
	}
}
