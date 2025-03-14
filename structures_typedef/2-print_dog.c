#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the details of a dog.
 * @d: Pointer to the struct dog.
 */
void print_dog(struct dog *d)
{
	if (d == NULL) /* Check if the struct pointer is NULL */
		return;

	/* Print Name, Age, and Owner, checking for NULL values */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	printf("Age: %.6f\n", d->age);

	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
