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
	char buffer[1024];
	int buffer_index = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	va_start(arguments, format);
		while (*format)
		{
			if (*format != '%')
			{	buffer[buffer_index++] = *format;
				char_print++;
		       
				if (buffer_index == sizeof(buffer) - 1)
				{
					write(1, buffer, buffer_index);
					buffer_index = 0; }
			}
			else
			{
				format++;
				if (*format == '\0')
					break;

				if (*format == '%')
				{	buffer[buffer_index++] = '%';
					char_print++;

					if (buffer_index == sizeof(buffer) - 1)
					{	write(1, buffer, buffer_index);
						buffer_index = 0; }
				}
				else if (*format == 'c')
				{	char c = va_arg(arguments, int);
					buffer[buffer_index++] = c;
					char_print++; }
				else if (*format == 's')
				{	char *string = va_arg(arguments, char*);

					while (*string)
					{	buffer[buffer_index++] = *string;
						char_print++;
						if (buffer_index == sizeof(buffer) - 1)
						{
							write(1, buffer, buffer_index);
							buffer_index = 0; }
					string++; }
				}
				else if (*format == 'd' || *format == 'i')
				{	int num = va_arg(arguments, int);
					int num_len = sprintf(buffer + buffer_index, "%d", num);
					
					buffer_index += num_len;
					char_print += num_len; }
				else if (*format == 'b')
				{	unsigned int num = va_arg(arguments, unsigned int);
					char_print += print_binary(num); }
				else if (*format == 'u')
				{	unsigned int num = va_arg(arguments, unsigned int);
					int num_len = sprintf(buffer + buffer_index, "%u", num);
					buffer_index += num_len;
					char_print += num_len; }
				else if (*format == 'o')
				{	unsigned int num = va_arg(arguments, unsigned int);
					int num_len = sprintf(buffer + buffer_index, "%o", num);
					buffer_index += num_len;
					char_print += num_len; }
				else if (*format == 'x' || *format == 'X')
				{	unsigned int num = va_arg(arguments, unsigned int);
					int num_len;
					if (*format == 'x')
						num_len = sprintf(buffer + buffer_index, "%x", num);
					else
						 num_len = sprintf(buffer + buffer_index, "%X", num);
					buffer_index += num_len;
					char_print += num_len; }
			}
			format++;
		}
		va_end(arguments);
		return (char_print);
}
