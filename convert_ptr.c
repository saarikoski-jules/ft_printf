/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_ptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 17:22:11 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/04 16:39:27 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char *convert_ptr(t_printf_arg *arg)
// {
// 	char *tmp;
// 	char *final;

// 	// if (arg->arg.i == 0)
// 		// printf("\n\nI AM THIS: %x\nWITH PRECISION: %d\n\n", arg->arg.p, arg->precision);
// 	if  (arg->arg.p == 0  && arg->precision == 0)
// 		tmp = ft_strdup("");
// 	else
// 		tmp = ft_ulltoa_base((long long)arg->arg.p, 16);//
// 	// printf("\n\nAFTER ULLTOA_BASE '%s'\n\n", tmp);
// 	if (!tmp)
// 		return (NULL);
// 	ft_tolowerstr(&tmp);
// 	final = ft_strjoin("00", tmp);//
// 	// printf("\n\nFINAL '%s'\n\n", final);
// 	free(tmp);
// 	if (!final)
// 		return (NULL);
// 	tmp = apply_precision(arg, final);
// 	free(final);
// 	// printf("\n\nTMP '%s'\n\n", tmp);
// 	if (!tmp)
// 		return (NULL);
// 	return (tmp);
// }

char *convert_ptr(t_printf_arg **arg)
{
	char *prec_buffer;
	char *num;
	char *buf;
	char *final;

	prec_buffer = apply_precision(arg);//
	if (!prec_buffer)
		return (NULL);
	if ((*arg)->arg.p == 0 && (*arg)->precision == 0)
		num = ft_strdup("");
	else
	{
		num = ft_ulltoa_base((long long)(*arg)->arg.p, 16);//
		// printf("\n\n'%s'\n\n", num);
	}
	if (!num)
	{
		free(prec_buffer);
		return (NULL);
	}
	ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num), num, ft_strlen(num));
	// printf("prec: '%s'\n\n", prec_buffer);
	// buf = ft_strjoin(prec_buffer, num);
	// free(prec_buffer);
	free(num);
	// if (!buf)
		// return (NULL);
	final = ft_strjoin("00", prec_buffer);
	// printf("\n\n'%s', len: %d, strlen: %d\n", final, (*arg)->arg_width, ft_strlen(final));
	(*arg)->arg_width += 2;
	// printf("'%s', len: %d, strlen: %d\n\n", final, (*arg)->arg_width, ft_strlen(final));
	// ft_memcpy(prec_buffer, "0x", 2);
	free(prec_buffer);
	if (!final)
		return (NULL);
	ft_tolowerstr(&final);
	// printf("\n\nprec: '%s'\n\n", final);
	return (final);
}

// TODO negative fake pointers do weird