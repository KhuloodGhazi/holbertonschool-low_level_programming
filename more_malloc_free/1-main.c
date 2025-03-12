#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *concat;

    concat = string_nconcat("Best ", "School !!!", 6);
    printf("%s\n", concat); /* Output should be: "Best School" */
    free(concat);

    concat = string_nconcat(NULL, "Hello", 3);
    printf("%s\n", concat); /* Output should be: "Hel" */
    free(concat);

    concat = string_nconcat("Hi ", NULL, 4);
    printf("%s\n", concat); /* Output should be: "Hi " */
    free(concat);

    concat = string_nconcat(NULL, NULL, 5);
    printf("%s\n", concat); /* Output should be: "" */
    free(concat);

    return (0);
}
