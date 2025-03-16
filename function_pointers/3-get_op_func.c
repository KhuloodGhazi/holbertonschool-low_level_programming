#include "3-calc.h"
#include <stddef.h>  /* Add this to define NULL */

/**
 * get_op_func - Selects the correct function to perform the operation
 * @s: The operator passed as an argument to the program
 *
 * Return: Pointer to the function corresponding to the operator
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}  /* Ensure that NULL is declared correctly */
    };
    int i = 0;

    while (ops[i].op != NULL)
    {
        if (*s == *(ops[i].op))  /* Compare operator */
            return (ops[i].f);
        i++;
    }

    return (NULL);  /* Return NULL if no matching operator is found */
}
