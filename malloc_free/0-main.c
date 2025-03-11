#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Tests the create_array function
 *
 * Return: Always 0.
 */
int main(void)
{
    char *buffer;

    buffer = create_array(98, 'H');
    if (buffer == NULL)
    {
        printf("Failed to allocate memory\n");
        return (1);
    }
    printf("Array successfully created!\n");
    free(buffer);
    return (0);
}
