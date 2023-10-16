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
	int ctr = 0;

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
		write(1, str, strlen(str));
		ctr += strlen(str);
		i++;
	}
	else if (format[i + 1] == '%')
	{
		_putchar(format[i]);
		ctr++;
		i++;
	}
	else if (format[i] == 'd' || format[i] == 'i')
		ctr += dandli(format, args, i);
	else
	{
		_putchar('%');
		_putchar(format[i + 1]);
		ctr += 2;
		i++;
	}
	return (ctr);
}
/**
  *dandli - handles d and i specifiers
  *@format: buffer var
  *@args: var of va_list data type
  *@i: int var
  *Return: int
  */
int  dandli(const char *format, va_list args, int i)
{
	int nomba, ctr = 0;
	unsigned long int a;
	char *str;

	if (format[i] == 'd' || format[i] == 'i')
	{
		nomba = va_arg(args, int);
		str = int_to_stng(nomba);
		for (a = 0; a < strlen(str); a++)
			_putchar(str[a]);
		ctr += strlen(str);
		free(str);
	}
	return (ctr);
}
/**
  *int_to_stng - converts int to string
  *@n: int var
  *Return: int
  */
char *int_to_stng(int n)
{
	int l = 0, temp = n, i;
	char *nomba;

	if (n == '-')
		n = n * -1;
	while (temp != 0)
	{
		temp = temp / 10;
		l++;
	}
	nomba = malloc(l + 1 * sizeof(char));
	if (nomba == 0)
		return (0);
	for (i = l - 1; i >= 0; i--)
	{
		nomba[i] = '0' + n % 10;
		n = n / 10;
	}
	nomba[l] = '\0';
	return (nomba);
}
