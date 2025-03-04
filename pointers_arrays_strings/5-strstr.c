#include "main.h"
#include <stddef.h> /* For NULL */

/**
 * _strstr - Locates a substring.
 * @haystack: The main string to search in.
 * @needle: The substring to find.
 *
 * Return: Pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (*needle == '\0')
		return (haystack); /* If needle is empty, return entire haystack */

	while (*haystack) /* Loop through haystack */
	{
		h = haystack;
		n = needle;

		while (*h && *n && (*h == *n)) /* Check for matching substring */
		{
			h++;
			n++;
		}

		if (!*n) /* If end of needle is reached, match found */
			return (haystack);

		haystack++;
	}

	return (NULL); /* No match found */
}
