#include "main.h"

/**
  *handle_see - handles other specifiers
  */
int handle_see(const char *format, va_list args)
{
	char cara, *str;
	int ctr = 0, i = 0;

	if (format[i] == 'c')
 	{
 		cara = va_arg(args, int);
		write(1, &cara, 1);
		ctr++;
 	}
 	else if (format[i] == 's')
  	{
 		str = va_arg(args, char *);
		write(1, &str, strlen(str));
		ctr += strlen(str);
	}
 	else if (format[i] == '%')
 	{
 		 write(1, &format[i], 1);
		 ctr++;
	}
	else
	{
		putchar('%');
		putchar(format[i]);
		ctr += 2;
	}
	return (ctr);
}
