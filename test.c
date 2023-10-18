#include <stdio.h>
#include "main.h"

int main(void)
{

	int ret;
	ret = _printf("what?");
	printf("\n%d\n", ret);
	ret = _printf("what%s", "The?");
	printf("\n%d\n", ret);
	ret = _printf("What%");
	printf("\n%d\n", ret);
	ret = _printf("what%s", NULL);
	printf("\n%d\n", ret);
	ret = _printf("what%d", 12);
	printf("\n%d\n", ret);
	ret = _printf("what%");
	printf("\n%d\n", ret);
	ret = _printf("what%c", "the");
	printf("\n%d\n", ret);
	ret = _printf("what%s", 'T');
	printf("\n%d\n", ret);

	return (0);
}

