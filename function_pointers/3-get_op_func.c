#include "3-calc.h"
#include <stddef.h>  /* Include to define NULL */

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: the operator passed as an argument
 * 
 * Return: pointer to the corresponding function or NULL if not found
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}  /* Sentinel value to indicate the end of the array */
    };

    int i = 0;

    /* Loop through the operators array and check for a match */
    while (ops[i].op != NULL)
    {
        if (*s == *(ops[i].op))  /* Match operator */
        {
            return ops[i].f;  /* Return the corresponding function pointer */
        }
        i++;
    }

    return NULL;  /* Return NULL if no match is found */
}
