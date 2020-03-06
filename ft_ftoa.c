/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 18:03:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 18:14:32 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>//

char *ft_ftoa(double num, int precision)
{
	int i;
	float f;
	char *i_str;

	i = (int)num;
	f = num - (float)i;

	i_str = ft_lltoa_base(num, 10);
	printf("int part %s\n", i_str);
	printf("float part %f\n", f);
	return (ft_strdup(""));
}