#include "main.h"

/**
  *riry - binary
  *@format: read-only
  *@args: va var
  *@i: int var
  *Return: pointer
  */
int riry(const char *format, va_list args, int i)
{
	int ctr = 0, b, c, start, end, temp;
	char *riry;

	if (format[i + 1] == 'b')
	{
		c = va_arg(args, unsigned int);
		riry = malloc((32 + 1) * sizeof(char));
		if (riry == NULL)
			return (-1);
		b = 0;
		while (c != 0)
		{
			if ((c % 2) == 1)
				riry[b] = '1';
			else
				riry[b] = '0';
			c /= 2;
			b++;
		}
		riry[b] = '\0';
		start = 0;
		end = strlen(riry) - 1;
		while (start < end)
		{
			temp = riry[start];
			riry[start] = riry[end];
			riry[end] = temp;
			start++;
			end--;
		}
		for (i = 0; riry[i] != '\0'; i++)
		{
			_putchar(riry[i]);
		}
		ctr += strlen(riry);
	}
	free(riry);
	return (ctr);
}
