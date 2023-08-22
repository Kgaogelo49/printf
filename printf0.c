#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 *
 * Return: the number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int char_print = 0;

	va_start(arguments, format);
	char_print = 0;

	while (*format != '\0')
	{
	int c;

	if (*format == '%')
	{
	format++;
	if (*format == '\0')
		break;
	if (*format == 'c')
	{
	c = va_arg(arguments, int);

	putchar(c);
	char_print++;
	}
	else if (*format == 's')
	{
	const char *string;

	string = va_arg(arguments, const char *);

	while (*string != '\0')
	{
	putchar(*string);
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

	va_end(arguments);

	return (char_print);
}
