#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: Pointer to the first occurrence of c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s); /* Return pointer to found character */
		s++;
	}
	if (c == '\0')
		return (s); /* Return pointer to null terminator */
	return (NULL); /* Return NULL if character is not found */
}
