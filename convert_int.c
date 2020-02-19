/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:25:42 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:05:55 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_int(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_lltoa_base(arg->arg.d, 10);//
	if (!tmp)
		return (NULL);
	final = apply_precision(arg, tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}

char *convert_uint(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_ulltoa_base(arg->arg.u, 10);//
	if (!tmp)
		return (NULL);
	final = apply_precision(arg, tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}

char *convert_iint(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_lltoa_base(arg->arg.i, 10);//
	if (!tmp)
		return (NULL);
	final = apply_precision(arg, tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}