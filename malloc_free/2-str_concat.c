#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Pointer to a newly allocated space in memory containing
 *         concatenated string. Returns NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
    char *concat;
    unsigned int i, j, len1 = 0, len2 = 0;

    if (s1 != NULL)
        while (s1[len1])
            len1++;
    if (s2 != NULL)
        while (s2[len2])
            len2++;

    concat = malloc(sizeof(char) * (len1 + len2 + 1)); /* +1 for null terminator */
    if (concat == NULL)
        return (NULL);

    for (i = 0; i < len1; i++) /* Copy s1 */
        concat[i] = s1[i];

    for (j = 0; j < len2; j++, i++) /* Copy s2 */
        concat[i] = s2[j];

    concat[i] = '\0'; /* Null-terminate the new string */
    return (concat);
}
