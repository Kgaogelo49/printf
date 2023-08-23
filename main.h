#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int binary(int num);
int octal(int num);
int print_binary(unsigned int num);

#endif /* MAIN_H */
