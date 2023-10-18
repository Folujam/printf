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
	int h, ctr = 0;

	if (format[i + 1] == 'c')
	{
		cara = (char) va_arg(args, int);
		_putchar(cara);
		ctr++;
		return (ctr);
	}
	else if (format[i + 1] == 's')
	{
		str = va_arg(args, char *);
		if (str != 0)
		{
			write(1, str, strlen(str));
			ctr += strlen(str);
			return (ctr);
		}
		else
		{
			write(1, "(null)", 6);
			ctr += 6;
			return (ctr);
		}
	}
	else
	{
		h = conti(format, args, i);
		ctr += h;
		return (ctr);

	}

}
/**
  *conti - continuation of handle_see
  *@format: string intake
  *@args: stored args var
  *@i: int var
  *Return: int
  */
int conti(const char *format, va_list args, int i)
{
	int dandli_return, ctr = 0;

	if (format[i + 1] == '%')
	{
		_putchar(format[i + 1]);
		ctr++;
		return (ctr);
	}
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		dandli_return = dandli(format, args, i);
		ctr += dandli_return;
		return (ctr);
	}
	else
	{
		_putchar('%');
		_putchar(format[i + 1]);
		ctr += 2;
		return (ctr);
	}
}
