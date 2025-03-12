#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: number of bytes to concatenate from s2.
 *
 * Return: pointer to newly allocated space in memory containing s1 followed by
 *         the first n bytes of s2, or NULL if function fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int len_s1 = 0, len_s2 = 0, i, j;

	/* Check if s1 is NULL, treat it as empty string */
	if (s1 == NULL)
		s1 = "";

	/* Check if s2 is NULL, treat it as empty string */
	if (s2 == NULL)
		s2 = "";

	/* Calculate length of s1 */
	while (s1[len_s1])
		len_s1++;

	/* Calculate length of s2 */
	while (s2[len_s2])
		len_s2++;

	/* If n is greater than or equal to len_s2, use the entire s2 */
	if (n >= len_s2)
		n = len_s2;

	/* Allocate memory for the concatenated string */
	concat_str = malloc(sizeof(char) * (len_s1 + n + 1));
	if (concat_str == NULL)
		return (NULL);

	/* Copy s1 into the new string */
	for (i = 0; i < len_s1; i++)
		concat_str[i] = s1[i];

	/* Copy the first n bytes of s2 into the new string */
	for (j = 0; j < n; j++)
		concat_str[i + j] = s2[j];

	/* Null-terminate the concatenated string */
	concat_str[i + j] = '\0';

	return (concat_str);
}
