#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Perform simple operations based on user input
 * @argc: argument count
 * @argv: argument vector (array of strings)
 *
 * Return: 0 on success, error code on failure
 */
int main(int argc, char *argv[])
{
    int num1, num2;
    int (*operation)(int, int);

    if (argc != 4)  // Ensure there are exactly 3 arguments (num1, operator, num2)
    {
        printf("Error\n");
        exit(98);  // Exit status 98 for incorrect argument count
    }

    num1 = atoi(argv[1]);  // Convert the first argument to an integer
    num2 = atoi(argv[3]);  // Convert the third argument to an integer

    // Get the corresponding function for the operator
    operation = get_op_func(argv[2]);

    // Check if the operator is valid
    if (operation == NULL)
    {
        printf("Error\n");
        exit(99);  // Exit status 99 for invalid operator
    }

    // Handle division or modulo by zero
    if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
    {
        printf("Error\n");
        exit(100);  // Exit status 100 for division or modulo by zero
    }

    // Perform the operation and print the result
    printf("%d\n", operation(num1, num2));
    return (0);
}
