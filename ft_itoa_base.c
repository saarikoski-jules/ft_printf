/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 12:38:44 by jsaariko       #+#    #+#                */
/*   Updated: 2019/12/05 22:52:14 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>//REMOVE

int ft_printf(const char *str, ...);
int ft_numlen_base(int n, int base);

char *str_fill(char *str, long num, int base, int len)
{
	while (num != 0)
	{
		len--;
		if (num % base >= 10)
			str[len] = num % base + 55;
		else
			str[len] = num % base + '0';
		num /= base;
	}
	return (str);
}

char *ft_itoa_base(int n, int base)
{
	int len;
	long num;
	char *str;
	int sign;

	sign = 1;
	num = (long)n;
	len = ft_numlen_base(n, base);
	if (base == 10 && num < 0)
	{
		num *= -1;
		sign = -1;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (sign == -1)
		str[0] = '-';
	if (num == 0)
		str[0] = '0';
	return (str_fill(str, num, base, len));
}

// int main(int amt, char **args)
// {
// 	if (amt == 3)
// 		ft_printf("%s\n", ft_itoa_base(ft_atoi(args[1]), ft_atoi(args[2])));
// 	else
// 		ft_printf("Wrong amt of args\n");
// 	return (0);
// }

//wtf do i do with negative numbers that are not base 10? is it undefined behavior?