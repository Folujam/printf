#include "main.h"

/**
  *handle_see - handles other specifiers
  *@format: format string
  *@args: stored arg vars
  *@i: int var carried from parent function
  *Return: int
  */
int handle_see(const char *format, va_list args, int i)
{
	char cara, *str;
	int dandli_return, ctr = 0;

	if (format[i + 1] == 'c')
	{
		cara = (char) va_arg(args, int);
		_putchar(cara);
		return (2);
		ctr++;
	}
	else if (format[i + 1] == 's')
	{
		str = va_arg(args, char *);
		write(1, str, strlen(str));
		ctr += strlen(str);
		return (2);
	}
	else if (format[i + 1] == '%')
	{
		_putchar(format[i]);
		ctr++;
		return (2);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		dandli_return = dandli(format, args, i);
		ctr += dandli_return;
		return (dandli_return);
	}
	else
	{
		_putchar('%');
		_putchar(format[i + 1]);
		ctr += 2;
		return (2);
	}
}
