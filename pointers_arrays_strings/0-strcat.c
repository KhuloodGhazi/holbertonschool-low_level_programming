#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string to append.
 *
 * Return: Pointer to the resulting string `dest`.
 */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    /* Find the end of dest */
    while (dest[i] != '\0')
        i++;

    /* Append src to dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Null-terminate */
    dest[i] = '\0';

    return dest;
}
