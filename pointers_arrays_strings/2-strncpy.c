#include "main.h"

/**
 * _strncpy - Copies a string
 * @dest: Destination buffer
 * @src: Source string to copy
 * @n: Maximum number of bytes to copy
 *
 * Return: Pointer to the resulting string `dest`
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i;

    /* Copy at most `n` characters from `src` to `dest` */
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    /* If `src` is shorter than `n`, pad the rest with `\0` */
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return (dest);
}
