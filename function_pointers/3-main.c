#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Perform simple operations based on user input
 * @argc: argument count
 * @argv: argument vector (array of strings)
 *
 * Return: 0 on success, exit code on failure
 */
int main(int argc, char *argv[])
{
    int num1, num2;
    int (*operation)(int, int);

    if (argc != 4)  /* Ensure there are exactly 3 arguments */
    {
        printf("Error\n");
        exit(98);  /* Exit with status 98 for incorrect argument count */
    }

    num1 = atoi(argv[1]);  /* Convert the first argument to an integer */
    num2 = atoi(argv[3]);  /* Convert the third argument to an integer */

    operation = get_op_func(argv[2]);  /* Get the function for the operator */

    if (operation == NULL)  /* Check if operator is valid */
    {
        printf("Error\n");
        exit(99);  /* Exit with status 99 for invalid operator */
    }

    if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)  /* Division by zero check */
    {
        printf("Error\n");
        exit(100);  /* Exit with status 100 for division by zero */
    }

    printf("%d\n", operation(num1, num2));  /* Perform the operation and print result */

    return (0);
}
