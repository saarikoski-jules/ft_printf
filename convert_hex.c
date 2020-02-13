/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:29:44 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/13 17:21:07 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convert_hex_lc(t_printf_arg *arg, char **str)
{
	*str = ft_lltoa_base(arg->arg.x, 16);
	*str = ft_tolowerstr(*str);
}

void convert_hex_uc(t_printf_arg *arg, char **str)
{
	*str = ft_lltoa_base(arg->arg.X, 16);
}