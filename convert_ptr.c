/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 17:22:11 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/13 18:15:50 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convert_ptr(t_printf_arg *arg, char **str)
{
	char *tmp;

	tmp = ft_tolowerstr(ft_ulltoa_base((long long)arg->arg.p, 16));
	*str = ft_strjoin("0x", tmp);
	free(tmp);
}
