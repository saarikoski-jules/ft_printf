/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 17:22:11 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:06:27 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_ptr(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_ulltoa_base((long long)arg->arg.p, 16);//
	if (!tmp)
		return (NULL);
	ft_tolowerstr(&tmp);
	final = ft_strjoin("00", tmp);//
	free(tmp);
	if (!final)
		return (NULL);
	tmp = apply_precision(arg, final);
	free(final);
	if (!tmp)
		return (NULL);
	return (tmp);
}
