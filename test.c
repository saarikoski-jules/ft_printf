#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

// char *ft_itoa_base(int n, int base);

int main()
{
	// int i;
	// int d;
	// char str[] = "lol";

	// i = 0;
	// d = 1324657840;
	// printf("%x\n", d);
	// // printf("%s\n", ft_itoa_base(d, 16));
	// char *hex = ft_itoa_base(d, 16);
	// while(hex[i] != '\0')
	// {
	// 	hex[i] = ft_tolower(hex[i]);
	// 	i++;
	// }
	// printf("%s\n", hex);

	// i = 0;
	// printf("%p\n", &i);
	// int *p_i = &i;






//    char  var = 'a';
//    char  *ip;

//    ip = &var;

//    printf("Address of var variable: %x\n", &var  );
//    printf("Address of var variable: %p\n", &var  );

//    printf("Address stored in ip variable: %x\n", ip );
//    printf("Address stored in ip variable: %p\n", ip );

//    printf("Value of *ip variable: %d\n", *ip );

	// long i,j;
    // int *p;
    // printf("%d %d\n", p, &i);
    // p = &i;
    // printf("%d %d\n", p, &i);
	int i;
    void *p;   /* a pointer to an integer */
    p = &i;
    
	

	// *p=5;
    // printf("%d %d\n", i, *p);
    printf("%d %lx %p\n", i, p, p);
	p = NULL;
    printf("%d %lx %p\n", i, p, p);

    return 0;

	// char *p = ft_itoa_base(ip, 16);

	// printf("d = %d\ni = %i\no = %o\nu = %u\nx = %x\nX = %X\nc = %c\n", d, d, d, d, d, d, *str);
	// printf("%    d\n", 12);
	return (0);
}

//work with negatives:

//d = digit (signed decimal) signed decimal in base 10
//i = integer (signed decimal)

//unsigned:

//o = unsigned octal
//u = unsigned decimal
//x = unsigned hexadecimal lowercase
//x = unsigned hexadecimal uppercase

//c = the first byte of the argument is printed. If i give it a pointer, (*str) it will print the first. It wont work with a string otherwise

// c check
// s check
// p check
// d check
// i check
// u
// x
// X check
// %