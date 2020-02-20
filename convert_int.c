/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:25:42 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 09:59:50 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_int(t_printf_arg *arg)
{
	char *tmp;
	char *final;


	// printf("\n\nIN CONVERT_INT %lld\n", arg->arg.i);
	tmp = ft_lltoa_base(arg->arg.i, 10);//
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