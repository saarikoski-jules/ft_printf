/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:29:44 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 20:45:09 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_hex_lc(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_lltoa_base(arg->arg.u, 16);//
	if (!tmp)
		return (NULL);
	ft_tolowerstr(&tmp);
	final = apply_precision(arg, tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}

char *convert_hex_uc(t_printf_arg *arg)
{
	char *tmp;
	char *final;
	
	tmp = ft_lltoa_base(arg->arg.u, 16);//
	if (!tmp)
		return (NULL);
	final = apply_precision(arg, tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}