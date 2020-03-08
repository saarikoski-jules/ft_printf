/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 18:03:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/08 20:10:58 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>//
#include <math.h>//

int get_last_dec(double num, int precision)
{
	int i;
	int d;
	double f;

	i = 0;
	d = (int)num;
	f = num - d;
	while(i <= precision)
	{
		f = f * 10;
		d = (int)f;
		f = f - d;
		i++;
	}
	return (d);
}



char *ft_ftoa(double num, int precision)
{
	int last;
	int laster;
	int i;
	long long d;
	double f;
	int prec;
	char *str;
	char *final;
	char *new_char;

	str = ft_strdup("");
	prec = precision + 1;
	d = (long long)num;
	f = num - d;
	printf("d: %lld, f: %.22f\n", d, f);
	last = get_last_dec(num, prec);
	while (0 < prec)
	{
		prec--;
		laster = get_last_dec(num, prec);
		if (last >= 5)
		{
			last = laster;
			laster++;
		}
		else
			last = 0;
		new_char = ft_lltoa_base(laster, 10);
		final = ft_strjoinchar(new_char, str);
		free(str);
		str = ft_strdup(final);
		free(final);
		printf("final %s\n", final);
	}


	// while (i < precision)
	// {
		
	// }
	// if (last >= 5)
	// {
		double to_times = (1 * pow(10, 12 * -1));
		// double to_times = 0.00000000000000000001;
		// printf("%.22f + %.22f =\n%.22f\n", num, to_times, num + to_times);
	// } 
	// printf("last: %d\n", last);
	return (ft_strdup(""));
}