#include "ft_printf.h"
#include <stdio.h>

int main()
{
	// char c;
	// int i = -12;
	char *str;
	str = ft_strdup("string");

	// ft_printf("%c\n", 'c');
	// ft_printf("%d\n", 12);
	// ft_printf("%012s\n", str);
	// ft_printf("%x\n", 12);
	// ft_printf("%X\n", 12);
	ft_printf("%16p\n", str);
	printf("real printf: '%16p'\n", str);
	// ft_printf("%-60p\n", str + 1);
	// ft_printf("%-12s\n", "");

	// printf("%c, %d, %s, %x, %X, %p, %p\n", 'c', 12, str, 12, 12, str, str + 1);
	free(str);
	// while (1);
	// ft_printf("str %12c, %000-s, %c, %c, %d, %d, %X, %p, %x %u %%", 'c', "I'm a string", '9', '2', 7, 12, 12, &c, 12, i);
	// printf("why");
	return (0);
}