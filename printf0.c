#include "main.h"

/**
 * print_binary - function to print an integer in binary format
 * @num: the number to be cnverted
 * Return: 1
 */
int print_binary(unsigned int num)
{	char binary_string[33];
	int index = 31;
	int i = 0;

	while (index >= 0 && ((num >> index) & 1) == 0)
	{	index--;
	}

	if (index < 0) 
	{	binary_string[0] = '0';
		return (write(1, binary_string, 1));
	}

	while (index >= 0)
	{	binary_string[i++] = ((num >> index) & 1) ? '1' : '0';
		index--;
	}

	return (write(1, binary_string, i));
}

/**
 * _printf - function that produces output according to a format
 * @format: the format string
 * Return:  the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int char_print = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	va_start(arguments, format);
		while (*format)
		{
			if (*format != '%')
			{	write(1, format, 1);
				char_print++; }
			else
			{
				format++;
				if (*format == '\0')
					break;

				if (*format == '%')
				{	write(1, format, 1);
					char_print++; }
				else if (*format == 'c')
				{	char c = va_arg(arguments, int);
					write(1, &c, 1);
					char_print++; }
				else if (*format == 's')
				{	char *string = va_arg(arguments, char*);
					int string_len = 0;

					while (string[string_len] != '\0')
					{	string_len++;
					}
					write(1, string, string_len);
					char_print += string_len;
				}
				else if (*format == 'd' || *format == 'i')
				{	int num = va_arg(arguments, int);
					char num_str[12];
					int num_len = sprintf(num_str, "%d", num);

					write(1, num_str, num_len);
					char_print += num_len; }
				else if (*format == 'b')
				{	unsigned int num = va_arg(arguments, unsigned int);
					char_print += print_binary(num); }
			}
			format++;
		}
		va_end(arguments);
		return (char_print);
}
