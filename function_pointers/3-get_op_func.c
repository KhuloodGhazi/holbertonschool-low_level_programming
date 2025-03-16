#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"
#include <stddef.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: The operator passed as argument
 *
 * Return: Pointer to the corresponding function, or NULL if invalid
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL} /* End of operations array */
    };
    int i = 0;

    while (ops[i].op != NULL)
    {
        if (strcmp(s, ops[i].op) == 0)
            return (ops[i].f); /* Return function pointer */
        i++;
    }

    return (NULL); /* Return NULL if no match is found */
}
