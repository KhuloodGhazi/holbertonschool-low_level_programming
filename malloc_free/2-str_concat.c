#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the newly allocated memory containing the
 * concatenated string, or NULL if the function fails to allocate memory.
 */
char *str_concat(char *s1, char *s2)
{
    char *result;
    int i, j, len1 = 0, len2 = 0;

    /* If either string is NULL, treat it as an empty string */
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    /* Find the length of s1 */
    while (s1[len1] != '\0')
        len1++;

    /* Find the length of s2 */
    while (s2[len2] != '\0')
        len2++;

    /* Allocate memory for the concatenated string */
    result = malloc(sizeof(char) * (len1 + len2 + 1)); /* +1 for the null terminator */
    if (result == NULL)
        return (NULL);

    /* Copy s1 into result */
    for (i = 0; i < len1; i++)
        result[i] = s1[i];

    /* Copy s2 into result */
    for (j = 0; j < len2; j++)
        result[i + j] = s2[j];

    /* Add the null terminator */
    result[i + j] = '\0';

    return (result);
}
