#include "main.h"

/**
 * _strncpy - Copies a string, up to n bytes.
 * @dest: Destination buffer.
 * @src: Source string.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to destination buffer.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* Fill the remaining space in dest with null bytes if src is shorter */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
