/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:25:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:52:26 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef char *(*func)(t_printf_arg *);

func choose_converter(t_printf_arg *cur_arg)
{
	if (cur_arg->conv == c)
		return (convert_char);
	else if (cur_arg->conv == d)
		return (convert_int);
	else if (cur_arg->conv == u)
		return (convert_uint);//
	else if (cur_arg->conv == i)
		return (convert_iint);//
	else if (cur_arg->conv == s)
		return (convert_str);
	else if (cur_arg->conv == x)
		return (convert_hex_lc);
	else if (cur_arg->conv == X)
		return (convert_hex_uc);
	else if (cur_arg->conv == p)
		return (convert_ptr);
	return (NULL);
}

char *execute_arg(t_printf_arg *arg)
{
	char	*final_str;
	char	*conv_str;
	func	conv;

	conv = choose_converter(arg);//
	if (!conv)
		return (NULL);
	conv_str = conv(arg);//
	if (!conv_str)
		return (NULL);
	final_str = fill_buffer(arg, conv_str);//
	if (!final_str)
	{
		free(conv_str);
		return (NULL);
	}
	add_conv(&final_str, conv_str, arg);
	free(conv_str);
	return (final_str);
}

//TODO i
//TODO u
//TODO malloc protection
//TODO error handling
//TODO norm


// precision applies to:
// d
// x
// X
// p
// u
// i
// o