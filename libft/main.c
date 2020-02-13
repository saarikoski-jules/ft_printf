#include <stdio.h>
#include "libft.h"
#include <limits.h>

int main()
{
	printf("%s\n", ft_lltoa_base(-200, 8));
	printf("%s\n", ft_ulltoa_base(9223372036854775890ull, 16));
	return (0);
}