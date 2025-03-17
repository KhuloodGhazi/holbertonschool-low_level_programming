#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on the format string
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0;
    char *str;
    char *separator = "";

    va_start(args, format);

    if (format) { /* First if: Checks if format is not NULL */
        while (format[i]) {
            if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's') { /* Second if: Checks for valid format specifiers */
                printf("%s", separator); /* Print the separator before each argument */
                
                if (format[i] == 'c') {
                    printf("%c", va_arg(args, int));
                }
                if (format[i] == 'i') {
                    printf("%d", va_arg(args, int));
                }
                if (format[i] == 'f') {
                    printf("%f", va_arg(args, double));
                }
                if (format[i] == 's') {
                    str = va_arg(args, char *);
                    printf("%s", str ? str : "(nil)"); /* Use "(nil)" for NULL string */
                }

                separator = ", "; /* After the first argument, add a separator */
            }
            i++;
        }
    }

    printf("\n");
    va_end(args);
}
