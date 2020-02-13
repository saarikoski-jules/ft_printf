#include "ft_printf.h"
#include <stdio.h>

int main()
{
	// char c;
	// int i = -12;
	char *str;
	str = ft_strdup("string");

	ft_printf("%c, %d, %s, %x, %X, %p, %p\n", 'c', 12, str, 12, 12, str, str + 1);
	printf("%c, %d, %s, %x, %X, %p, %p\n", 'c', 12, str, 12, 12, str, str + 1);
	free(str);
	while (1);
	// ft_printf("str %12c, %000-s, %c, %c, %d, %d, %X, %p, %x %u %%", 'c', "I'm a string", '9', '2', 7, 12, 12, &c, 12, i);
	// printf("why");
	return (0);
}