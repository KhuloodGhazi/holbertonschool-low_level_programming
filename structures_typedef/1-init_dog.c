#include <stddef.h> /* Include this for NULL */
#include "dog.h"

/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to struct dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL) /* Check if the pointer is valid */
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
