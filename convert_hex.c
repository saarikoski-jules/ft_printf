/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 16:29:44 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/21 23:55:15 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char *convert_hex_lc(t_printf_arg *arg)
// {
// 	char *tmp;
// 	char *final;

// 	tmp = ft_lltoa_base(arg->arg.u, 16);//
// 	if (!tmp)
// 		return (NULL);
// 	ft_tolowerstr(&tmp);
// 	// final = apply_precision(arg, tmp);//
// 	final = apply_precision(arg);//
// 	free(tmp);
// 	if (!final)
// 		return (NULL);
// 	return (final);
// }

char *convert_hex_lc(t_printf_arg *arg)
{
	char *prec_buffer;
	char *num;
	char *final;

	prec_buffer = apply_precision(arg);//
	if (!prec_buffer)
		return (NULL);
	if (arg->arg.u == 0 && arg->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)arg->arg.u, 16);//
	if (!num)
	{
		free(prec_buffer);
		return (NULL);
	}
	ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num), num, ft_strlen(num));
	// final = ft_strjoin(prec_buffer, num);
	// free(prec_buffer);
	free(num);
	// if (!final)
		// return (NULL);
	ft_tolowerstr(&prec_buffer);
	return (prec_buffer);
}

// char *convert_hex_uc(t_printf_arg *arg)
// {
// 	char *tmp;
// 	char *final;
	
// 	tmp = ft_lltoa_base(arg->arg.u, 16);//
// 	if (!tmp)
// 		return (NULL);
// 	// final = apply_precision(arg, tmp);//
// 	final = apply_precision(arg);//
// 	free(tmp);
// 	if (!final)
// 		return (NULL);
// 	return (final);
// }

// TODO Check which type hexadecimals are stored as


char *convert_hex_uc(t_printf_arg *arg)
{
	char *prec_buffer;
	char *num;
	char *final;

	prec_buffer = apply_precision(arg);//
	if (!prec_buffer)
		return (NULL);
	if (arg->arg.u == 0 && arg->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)arg->arg.u, 16);//
	if (!num)
	{
		free(prec_buffer);
		return (NULL);
	}
	ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num), num, ft_strlen(num));
	// final = ft_strjoin(prec_buffer, num);
	// free(prec_buffer);
	free(num);
	// if (!final)
		// return (NULL);
	return (prec_buffer);
}

// char *convert_hex_uc(t_printf_arg *arg)
// {
// 	char *prec_buffer;
// 	char *num;
// 	char *final;

// 	prec_buffer = apply_precision(arg);//
// 	if (!prec_buffer)
// 		return (NULL);
// 	if (arg->arg.u == 0 && arg->precision == 0)
// 		num = ft_strdup("");
// 	else
// 		num = ft_lltoa_base((long long)arg->arg.i, 16);//
// 	if (!num)
// 	{
// 		free(prec_buffer);
// 		return (NULL);
// 	}
// 	final = ft_strjoin(prec_buffer, num);
// 	free(prec_buffer);
// 	free(num);
// 	if (!final)
// 		return (NULL);
// 	return (final);
// }
