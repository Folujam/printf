#include "main.h"

/**
  *handle_see - handles other specifiers
  *@format: format string
  *@args: stored arg vars
  *Return: int
  */
int handle_see(const char *format, va_list args)
{
	char cara, *str;
	int ctr = 0, i = 0;

	if (format[i + 1] == 'c')
	{
		cara = (char) va_arg(args, int);
		_putchar(cara);
		i++;
		ctr++;
	}
	else if (format[i + 1] == 's')
	{
		str = va_arg(args, char *);
		write(1, &str, strlen(str));
		ctr += strlen(str);
		i++;
	}
	else if (format[i + 1] == '%')
	{
		_putchar(format[i]);
		ctr++;
		i++;
	}
	else
	{
		_putchar('%');
		ctr++;
		i++;
	}
	return (ctr);
}
