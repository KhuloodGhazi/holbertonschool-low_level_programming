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

    if (format) {
        while (format[i]) {
            if (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's')
            {
                if (format[i] == 'c')
                    printf("%s%c", separator, va_arg(args, int));
                else if (format[i] == 'i')
                    printf("%s%d", separator, va_arg(args, int));
                else if (format[i] == 'f')
                    printf("%s%f", separator, va_arg(args, double)); /* 'f' promoted to double */
                else if (format[i] == 's')
                {
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(nil)";
                    printf("%s%s", separator, str);
                }
                separator = ", ";
            }
            i++;
        }
    }

    printf("\n");

    va_end(args);
}
