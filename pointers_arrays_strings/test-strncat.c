#include "main.h"
#include <stdio.h>

/**
 * main - Test the _strncat function.
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("Before _strncat: %s\n", s1);

    ptr = _strncat(s1, s2, 5);  /* Append first 5 chars of s2 */
    printf("After _strncat (n=5): %s\n", ptr); /* ✅ Use ptr in printf */

    ptr = _strncat(s1, s2, 50); /* Append entire s2 */
    printf("After _strncat (n=50): %s\n", ptr); /* ✅ Use ptr in printf */

    return (0);
}
