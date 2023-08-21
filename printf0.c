#include "main.h"
#include <stdarg.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: number of the formated characters
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list arguments;

	va_start(arguments, format);

	if (format == NULL)
	{
	return (-1);
	}
	va_start(arguments, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(arguments, int);
				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(arguments, char*);
				int string_len =0;

				while(string[string_len] != '\0')
				{
					string_len++;
				}
				write(1, string, string_len);
				char_print += string_len++;
			}
		}
		format++;
	}
	va_end(arguments);
	return char_print;
}
