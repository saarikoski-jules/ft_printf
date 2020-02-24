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
	int ret;

	// ret = ft_printf("'FT_PRINTF:\nThis is a string %s with the length of %0-12.7d\nwith the ptr address of %p\nAlso, this is hex %X\ni = %i\nproper u = %u\nbad u = %u'\n", str, 6, str, 0x70, 12, 12, -12);
	// ft_printf("RETURN VALUE %d\n\n", ret);
	// ret = printf("REAL PRINTF:\n'This is a string %s with the length of %0-12.7d\nwith the ptr address of %p\nAlso, this is hex %X\ni = %i\nproper u = %u\nbad u = %u'\n", str, 6, str, 0x70, 12, 12, -12);
	// printf("RETURN VALUE %d\n\n", ret);
	// printf("aa\n");


	// ft_printf(" (%d)\n", ft_printf("-04.8: |%-04.8s|", "0"));
	// printf(" (%d)\n", ft_printf("*8.4: |%*.4s|", 8, "012345"));
	// ft_printf(" (%d)\n", ft_printf("*8.4: |%*.4s|", 8, "012345"));

	// printf("lol");
	// ft_printf("%%");
	// printf("%%");

// FIX THIS!!!!!:

	// printf("printf: Text1\nText2\nTest4%CTest5\n", 0x0381);
	// ft_printf("ft_printf: Text1\nText2\nTest4%CTest5\n", 0x0381);
//!!!!!!!!


	// ft_printf("this is a number '%0-12d'\n", 7);
	// printf(" (%d)\n", printf("*(-03): |%*i|", -03, 42));
	// ft_printf(" (%d)\n", ft_printf("*(-03): |%*i|", -03, 42));

	// printf("Text1\nText2\n%sTest4%CTest5\n", "Text3\n", 0x0381);


	// printf("'%5.*.1d'", 12, 7);s


	// printf("%d\n", 0);
	ft_printf("%d\n", 0);

	free(str);
	// while (1);
	// ft_printf("str %12c, %000-s, %c, %c, %d, %d, %X, %p, %x %u %%", 'c', "I'm a string", '9', '2', 7, 12, 12, &c, 12, i);
	// printf("why");
	return (0);
}