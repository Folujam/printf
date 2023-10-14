#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
  *_printf - print format
  *@format: const char var
  *Return: int(number of char printed)
  */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;
	char cara, *str;

	if (format == 0)
	{
		return (0);
	}
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				cara = va_arg(args, int);
				write(1, &cara, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				write(1, str, stl(str));
				i += stl(str);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
			}
			i++;
		}
	}
	va_end(args);
	return (i);
}
/**
  *stl - string lenght
  *@s: string pointer
  *Return: int
  */
int stl(char *s)
{
	int l = 0;
	while (s[l] != '\0')
	{
		l++;
	}
	return (l);
}
