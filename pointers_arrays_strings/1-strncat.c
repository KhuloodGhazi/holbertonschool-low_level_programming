#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src.
 * @dest: Destination string.
 * @src: Source string to append.
 * @n: Number of bytes to append from src.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	/* Find the end of dest */
	while (dest[i] != '\0')
		i++;

	/* Append at most n bytes of src to dest */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Null-terminate dest */
	dest[i] = '\0';

	return (dest);
}
