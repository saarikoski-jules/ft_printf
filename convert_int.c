/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:25:42 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/24 16:04:55 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char *convert_int(t_printf_arg *arg)
{
	char *prec_buffer;
	char *num;
	char *final;

	// printf("\n\nIN CONVERT INT: %u\n\n", arg->arg.u);
	prec_buffer = apply_precision(arg);//
	if (!prec_buffer)
		return (NULL);
	if (arg->arg.i == 0 && arg->precision == 0)
		num = ft_strdup("");
	else
		num = ft_lltoa_base((long long)arg->arg.i, 10);//
	if (!num)
	{
		free(prec_buffer);
		return (NULL);
	}
	//lets hope this monster works
	// printf("\n\nprec buf len: %d\nnum strlen: %d\n, num: %s\n\n", ft_strlen(prec_buffer), ft_strlen(num), num);
	ft_memcpy(prec_buffer + ft_strlen(prec_buffer) - ft_strlen(num), num, ft_strlen(num)); //THIS MONSTER DOESN'T WORK. FIX.
	// printf("\n\nprec_buffer: '%s', num '%s', ft_strlen: %d\n\n", prec_buffer, num, ft_strlen(num));
	// final = ft_strjoin(prec_buffer, num);
	// free(prec_buffer);
	free(num);
	// if (!final)
		// return (NULL);
	return (prec_buffer);
}

char *convert_uint(t_printf_arg *arg)
{
	char *prec_buffer;
	char *num;
	char *final;

	// printf("\n\nIN CONVERT UINT: %u\n\n", arg->arg.u);
	prec_buffer = apply_precision(arg);//
	// printf("\napply prec: '%s'\n", prec_buffer);

	if (!prec_buffer)
		return (NULL);
	if (arg->arg.u == 0 && arg->precision == 0)
		num = ft_strdup("");
	else
		num = ft_ulltoa_base((long long)arg->arg.u, 10);//
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
		// printf("\nprec buf: %s\n", prec_buffer);
	return (prec_buffer);
}

// char *convert_uint(t_printf_arg *arg)
// {
// 	char *tmp;
// 	char *final;

// 	tmp = ft_ulltoa_base(arg->arg.u, 10);//
// 	if (!tmp)
// 		return (NULL);
// 	// final = apply_precision(arg, tmp);//
// 	final = apply_precision(arg);//
// 	free(tmp);
// 	if (!final)
// 		return (NULL);
// 	return (final);
// }

// char *convert_int(t_printf_arg *arg)
// {
// 	char *tmp;
// 	char *final;


// 	// printf("\n\nIN CONVERT_INT %lld\n", arg->arg.i);
// 	tmp = ft_lltoa_base(arg->arg.i, 10);//
// 	if (!tmp)
// 		return (NULL);
// 	// final = apply_precision(arg, tmp);//
// 	final = apply_precision(arg);//

// 	free(tmp);
// 	if (!final)
// 		return (NULL);
// 	return (final);
// }

char *convert_iint(t_printf_arg *arg)
{
	char *tmp;
	char *final;

	tmp = ft_lltoa_base(arg->arg.i, 10);//
	if (!tmp)
		return (NULL);
	// final = apply_precision(arg, tmp);//
	final = apply_precision(arg);//
	free(tmp);
	if (!final)
		return (NULL);
	return (final);
}

