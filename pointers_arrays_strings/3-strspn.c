#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The main string
 * @accept: The substring containing the characters to match
 *
 * Return: The number of bytes in s that match bytes in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		int found = 0; /* Flag to check if char is in accept */

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				found = 1;
				break;
			}
		}

		if (!found)
			break;
	}

	return (count);
}
