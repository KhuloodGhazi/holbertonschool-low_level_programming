#include "main.h"
#include <stddef.h> /* For NULL */

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to be searched.
 * @accept: The string containing the characters to match.
 *
 * Return: Pointer to the first matching byte in s, or NULL if not found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s) /* Loop through each character in s */
	{
		for (i = 0; accept[i]; i++) /* Check if current char in s matches accept */
		{
			if (*s == accept[i])
				return (s); /* Return pointer to the matching character */
		}
		s++; /* Move to next character */
	}
	return (NULL); /* No match found */
}
