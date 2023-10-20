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
	unsigned int a;
	int ctr = 0, b;
	char *riry, *biform = "01";

	if (format[i + 1] == 'b')
	{
		a = va_arg(args, int);
		riry = malloc((32 + 1) * sizeof(char));
		if (riry == NULL)
			return (NULL);
		if (a == 0)
		{
			riry[i + 1] = '0';
			ctr++;
			return (ctr);
		}
		else
		{
			b = 0;
			while (a != 0)
			{
				riry[b + 1] = biform[a % 2];
				a /= 2;
			}
			while (b >= 0; b += 1; b --)
			{
				riry[i + 1] = riry[b + 1];
				putchar(riry[i] + '0');
				ctr++;
			}
		}
		riry[i] = '\0';
	}
	free(riry);
	return (ctr);
}
