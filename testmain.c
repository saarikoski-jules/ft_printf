#include "ft_printf.h"
#include <stdio.h>

int main()
{
	// char c;
	// int i = -12;
	char *str;
	str = ft_strdup("string");

	int d = 12;

	// ft_printf("%.7x\n", d);
	// printf("'%.7x'\n", d);

	// ft_printf("'%.20c'\n", 'c');
	// printf("c: '%.20c'\n", 'c');
	// ft_printf("'%.20d'\n", 12);
	// printf("d: '%.20d'\n", 12);
	// ft_printf("'%.20s'\n", str);
	// printf("s: '%.20s'\n", str);
	// ft_printf("'%.20x'\n", 12);
	// printf("x: '%.20x'\n", 12);
	// ft_printf("'%.20X'\n", 12);
	// printf("X: '%.20X'\n", 12);
	// ft_printf("'%.20p'\n", 012);
	// printf("p: '%.20p'\n", 012);
	// ft_printf("%.20p\n", str + 1);
	// printf("p: '%.20p'\n", str + 1);
	// ft_printf("%.20s\n", "");
	// printf("s: '%.20s'\n", "");


	// ft_printf("'%20c'\n", 'c');
	// printf("c: '%20c'\n", 'c');
	// ft_printf("'%20d'\n", 12);
	// printf("d: '%20d'\n", 12);
	// ft_printf("'%20s'\n", str);
	// printf("s: '%20s'\n", str);
	// ft_printf("'%20x'\n", 12);
	// printf("x: '%20x'\n", 12);
	// ft_printf("'%20X'\n", 12);
	// printf("X: '%20X'\n", 12);
	// ft_printf("'%20p'\n", 012);
	// printf("p: '%20p'\n", 012);
	// ft_printf("%020p\n", str + 1);
	// printf("p: '%020p'\n", str + 1);
	// ft_printf("%20s\n", "");
	// printf("s: '%20s'\n", "");


	// ft_printf("'%0-20.7p'\n", str + 1);
	// printf("'%0-20.7p'\n", str + 1);


	// printf("i: '%23.20i'\n", 12);
	// printf("u: '%.20u'\n", 12);
	// printf("o: '%.20o'\n", 12);

	// printf("%c, %d, %s, %x, %X, %p, %p\n", 'c', 12, str, 12, 12, str, str + 1);

	ft_printf("'This is a string %s with the length of %0-12.7d'\n", str, 6);
	printf("'This is a string %s with the length of %0-12.7d'\n", str, 6);
	// printf("aa\n");
	free(str);
	// while (1);
	// ft_printf("str %12c, %000-s, %c, %c, %d, %d, %X, %p, %x %u %%", 'c', "I'm a string", '9', '2', 7, 12, 12, &c, 12, i);
	// printf("why");
	return (0);
}