#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees a dog structure
 * @d: The dog to free
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        free(d->name);  // Free the dynamically allocated memory for name
        free(d->owner); // Free the dynamically allocated memory for owner
        free(d);         // Finally, free the dog struct itself
    }
}
