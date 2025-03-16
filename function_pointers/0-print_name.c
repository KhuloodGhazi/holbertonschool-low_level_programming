#include "function_pointers.h"

/**
 * print_name - Calls a function to print a name in a specific format
 * @name: The name to be printed
 * @f: Pointer to a function that takes a char * and prints the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL) /* Check for NULL to avoid crashes */
		f(name);
}
