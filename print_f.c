#include "main.h"
/**
 * _print - p
 *@format: the space holders
 *@...: the variables
 *Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	char *list;
	char valeur;

	va_list array;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(array, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == 'c')
			{
				valeur = va_arg(array, int);
				write(1, &valeur, 1);
				count++;
			}
			else if (*format == 's')
			{
				list = va_arg(array, char *);
				if (list != NULL)
				{
					write(1, list, strlen(list));
					count += strlen(list);
				}
				else
				{
					write(1, "(null)", 6);
					count += 6;
				}
			}
			else if (*format == '%')
			{

				write(1, format, 1);
				count++;
			}
		}
		format++;
	}

	va_end(array);
	return (count);
}
