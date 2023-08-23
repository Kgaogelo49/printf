#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: the format string
 *
 * Return:  the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int char_print;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arguments, format);
	char_print = 0;

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
				{
					break;
				}
				if (*format == '%')
				{
					write(1, format, 1);
					char_print++;
				}
				else if (*format == 'c')
				{
					char c;

					c = va_arg(arguments, int);
					write(1, &c, 1);
					char_print++;
				}
				else if (*format == 's')
				{
					char *string;
					int string_len;

					string = va_arg(arguments, char*);
					string_len = 0;

					while (string[string_len] != '\0')
					{
						string_len++;
					}
					write(1, string, string_len);
					char_print += string_len;
				}
			}
			format++;
		}
		va_end(arguments);

		return (char_print);
}
