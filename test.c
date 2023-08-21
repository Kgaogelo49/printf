#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char ch = 'A';
	char *string = "Hello, World!";

	int char_print = _printf("Character: %c, String: %s, Percent: %%\n", ch, string);

	printf("\nTotal characters printed: %d\n", char_print);

	return (0);
}
