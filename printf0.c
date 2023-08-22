#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - nction that produces output according to a format
 * @format: the format string
 *
 * Return:  the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_print;

	va_start(args, format);
	char_print = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		if (*format == '\0')
			break;
		if (*format == 'c')
		{
                	int c = va_arg(args, int);
                	_putchar(c);
                	char_print++;
		}
		else if (*format == 's')
		{
			const char *string = va_arg(args, const char *);

			while (*string != '\0')
			{
				_putchar(*string);
				string++;
				char_print++;
			}
		}
		else if (*format == '%')
		{
			putchar('%');
			char_print++;
		}
		}
		else
		{
		putchar(*format);
		char_print++;
		}
		format++;
	}

	va_end(args);

	return (char_print);
}
