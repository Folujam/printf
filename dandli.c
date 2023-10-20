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

	if (n == INT_MIN || n == INT_MAX || n == 0)
	{
		nomba = chkz(n);
		return (nomba);
	}
	if (n < 0)
	{
		isN = true;
		n = abs(n);
	}
	while (temp != 0)
	{
		temp = temp / 10;
			l++;
	}
	nomba = malloc((l + 1) * sizeof(char));
	if (nomba == NULL)
		return (NULL);
	for (i = l - 1; i >= 0; i--)
	{
		nomba[i] = '0' + (n % 10);
		n = n / 10;
	}
	if (isN)
	{
		for (i = l - 1; i >= 0; i--)
			nomba[i + 1] = nomba[i];
		nomba[0] = '-';
		nomba[l + 1] = '\0';
	}
	else
		nomba[l] = '\0';
	return (nomba);
}
/**
  *chkz - checks if n = 0 or int_min
  *@n: passed int
  *Return: str ptr
  */
char *chkz(int n)
{
	char *nomba;

	if (n == INT_MIN)
	{
		nomba = malloc(12 * sizeof(char));
		if (nomba == 0)
			return (0);
		strcpy(nomba, "-2147483648");
		return (nomba);
	}
	else if (n == 0)
	{
		nomba = malloc(2 * sizeof(char));
		if (nomba == 0)
			return (0);
		nomba[0] = '0';
		nomba[1] = '\0';
		return (nomba);
	}
	else if (n == INT_MAX)
	{
		nomba = malloc(11 * sizeof(char));
		if (nomba == 0)
			return (0);
		strcpy(nomba, "2147483647");
		return (nomba);
	}
	else
		return (0);
}
