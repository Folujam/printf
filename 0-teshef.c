#include "main.h"

/**
  *_printf - print format
  *@format: const char var
  *Return: int(number of char printed)
  */
int _printf(const char *format, ...)
{
	int i, ctr = 0;
	va_list args;

	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	va_start(args, format);
	if (*format)
	{
		for (i = 0; format[i]; i++)
		{
			if (format[i] != '%')
			{
				write(1, &format[i], 1);
				ctr++;
			}
			else
			{
				i++;
				if (format[i] == '\0')
				{
					va_end(args);
					return (-1);
				}
				ctr += handle_see(format, args);
			}
		}
	}
	va_end(args);
	return (i);
}
