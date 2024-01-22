#include "main.h"
/**
 * _print - p
 *@format: the space holders
 *@...: the variables
 *Return: int
 */
int _printf(const char *format, ...)
{
    int count=0;
    char carachter;
    char *string;
    va_list array;

    if (format == NULL)
    return(-1);
    va_start(array, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case '\0':
                break;
            case '%':
                write(1, format, 1);
                count++;
                break;
            case 'c':
                carachter = va_arg(array, int);
                write(1, &carachter, 1);
                count++;
                break;
            case 's':
                string = va_arg(array, char *);
                write(1, string, strlen(string));
                count += (int)strlen(string);
                break;
            default:
                write(1, format, 1);
                break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(array);
    return(count);
}