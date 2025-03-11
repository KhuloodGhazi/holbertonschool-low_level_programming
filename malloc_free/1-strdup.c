#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           containing a copy of the given string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	/* Check if str is NULL */
	if (str == NULL)
		return (NULL);

	/* Calculate the length of str */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for duplicate string (+1 for null terminator) */
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	/* Copy the string */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
