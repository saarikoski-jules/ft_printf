/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 17:22:11 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 19:04:23 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_ptr(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_ulltoa_base((long long)arg->arg.p, 16);
	ft_tolowerstr(&tmp);
	final = ft_strjoin("00", tmp);
	free(tmp);
	return (final);
}
