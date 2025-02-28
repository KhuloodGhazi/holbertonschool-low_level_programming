#include "main.h"

/**
* _strcmp - Compares two strings
* @s1: First string
* @s2: Second string
*
* Return: An integer difference between first non-matching characters
*         0 if strings are equal, positive if s1 > s2, negative if s1 < s2
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*s1 - *s2);
}
