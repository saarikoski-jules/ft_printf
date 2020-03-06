/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_float.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 17:51:25 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/06 18:02:51 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

char	*convert_float(t_printf_arg **arg)
{
	// printf("%f\n", (*arg)->arg.f);
	int i;
	float f;

	i = (int)(*arg)->arg.f;
	f = (*arg)->arg.f - (float)i;

	printf("int part %d\n", i);
	printf("float part %f\n", f);

	return (ft_strdup(""));
}