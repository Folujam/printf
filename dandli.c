#include "main.h"

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

	if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		nomba = va_arg(args, int);
		str = int_to_stng(nomba);
		for (a = 0; a < strlen(str); a++)
			_putchar(str[a]);
		ctr += strlen(str);
		free(str);
		return (ctr);
	}
	return (0);
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
	bool isN = false;

	if (n < 0)
	{
		isN = true;
		n = n * -1;
		l += 1;
	}
	while (temp != 0)
	{
		temp = temp / 10;
			l++;
	}
	nomba = malloc((l + 1) * sizeof(char));
	if (nomba == 0)
		return (0);
	for (i = l - 1; i >= 0; i--)
	{
		nomba[i] = '0' + n % 10;
		n = n / 10;
	}
	if (isN)
	{
		for (i = l - 1; i >= 0; i--)
		{
			nomba[i + 1] = nomba[i];
		}
		nomba[0] = '-';
		nomba[l] = '\0';
	}
	else
		nomba[l] = '\0';
	return (nomba);
}
