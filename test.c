#include <stdio.h>

int main()
{
	int i;
	int d;
	char str[] = "lol";

	i = 332;
	d = 20;
	// printf("d = %d\ni = %i\no = %o\nu = %u\nx = %x\nX = %X\nc = %c\n", d, d, d, d, d, d, *str);
	printf("%    d\n", 12);
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
// p
// d check
// i check
// u
// x
// X
// %