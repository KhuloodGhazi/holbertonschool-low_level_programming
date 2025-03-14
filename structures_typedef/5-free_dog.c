#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog
 * @d: Pointer to the dog to be freed
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        free(d->name);  /* Free the dynamically allocated memory for name */
        free(d->owner); /* Free the dynamically allocated memory for owner */
        free(d);        /* Free the memory for the dog structure itself */
    }
}
