#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of elements in the array.
 * @size: size of each element.
 *
 * Return: pointer to the allocated memory, or NULL if it fails or if nmemb or size is 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;

    /* Check if nmemb or size is 0, return NULL in that case */
    if (nmemb == 0 || size == 0)
        return (NULL);

    /* Allocate memory for the array */
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);

    /* Initialize the memory to zero */
    memset(ptr, 0, nmemb * size);

    return (ptr);
}
