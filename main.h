#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle_see(const char *format, va_list agrs, int i);
int dandli(const char *format, va_list agrs, int i);
char *int_to_stng(int n); 
int conti(const char *format, va_list args, int i);

#endif
