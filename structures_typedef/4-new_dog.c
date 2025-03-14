#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog.
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;

    /* Allocate memory for the dog struct */
    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);

    /* Allocate memory for name and owner strings and copy values */
    new_dog->name = malloc(strlen(name) + 1);
    if (new_dog->name == NULL)
    {
        free(new_dog);  /* Free the allocated memory for dog struct */
        return (NULL);
    }
    strcpy(new_dog->name, name);

    new_dog->owner = malloc(strlen(owner) + 1);
    if (new_dog->owner == NULL)
    {
        free(new_dog->name);  /* Free the allocated memory for name */
        free(new_dog);  /* Free the allocated memory for dog struct */
        return (NULL);
    }
    strcpy(new_dog->owner, owner);

    /* Set the age */
    new_dog->age = age;

    return (new_dog);
}
