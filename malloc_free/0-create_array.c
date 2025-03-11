#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it.
 * @size: The size of the array.
 * @c: The character to initialize the array with.
 *
 * Return: Pointer to the array, or NULL if size is 0 or malloc fails.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* Check if size is 0 */
	if (size == 0)
		return (NULL);

	/* Allocate memory */
	array = malloc(size * sizeof(char));
	if (array == NULL)
		return (NULL);

	/* Initialize array with the given char */
	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
