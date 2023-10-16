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

	if (format == NULL || strcmp(format, "") == 0 )
		return (-1);
	va_start(args, format);
	if (*format)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] != '%')
			{
				write(1, &format[i], 1);
				ctr++;
			}
			else
			{
				if (format[i + 1] == '\0')
				{
					_putchar('%');
					ctr++;
					va_end(args);
					return (ctr);
				}
				else
				{
					ctr += handle_see(format, args, i);
				}
			}
		}
	}
	va_end(args);
	return (ctr);
}
