#include "main.h"
#include <stddef.h> /* Include for NULL */

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to be searched
 * @accept: The string containing the set of bytes to match
 *
 * Return: Pointer to the byte in `s` that matches one of the bytes in `accept`
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
    int i, j;

    for (i = 0; s[i] != '\0'; i++) { /* Loop through each character in `s` */
        for (j = 0; accept[j] != '\0'; j++) { /* Loop through each character in `accept` */
            if (s[i] == accept[j]) { /* Check for a match */
                return &s[i]; /* Return the address of the matching character */
            }
        }
    }
    return NULL; /* Return NULL if no match found */
}
