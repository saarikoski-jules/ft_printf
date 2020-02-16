/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:25:42 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:39:27 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_int(t_printf_arg *arg)
{
	char *tmp;

	tmp = ft_lltoa_base(arg->arg.d, 10);
	return (tmp);
	// *str = ft_strjoin(ft_itoa(arg->arg.d), *str);
}