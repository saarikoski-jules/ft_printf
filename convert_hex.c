/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:29:44 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:40:49 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_hex_lc(t_printf_arg *arg)
{
	char *tmp;

	tmp = ft_lltoa_base(arg->arg.x, 16);
	ft_tolowerstr(&tmp);
	return (tmp);
}

char *convert_hex_uc(t_printf_arg *arg)
{
	char *tmp;
	
	tmp = ft_lltoa_base(arg->arg.X, 16);
	return (tmp);
}