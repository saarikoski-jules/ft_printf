/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:25:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 19:16:03 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef char *(*func)(t_printf_arg *);

func choose_converter(t_printf_arg *cur_arg)
{
	if (cur_arg->conv == c)
	{
		// printf("conversion type %d\n", cur_arg->conv);
		return (convert_char);
	}
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

	//it segfaults here??? on the second run?
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
	// printf("\n\nconv_str: '%s'\n", conv_str);
	// conv_str = NULL;
	if (!conv_str)
		return (NULL);
	// printf("\n\nCONV_STR '%s'\n\n", conv_str);
	final_str = fill_buffer(arg, conv_str);//
	printf("\n\nFINAL_STR '%s'\n\n", final_str + 2);
	// printf("final_str: '%s'\n\n", final_str);
	// printf("segfault???\n");
	if (!final_str)
	{
		free(conv_str);
		return (NULL);
	}
	add_conv(&final_str, conv_str, arg);
	// printf("\n\nFINAL_STR '%s'\nCONV_STR '%s\n\n", final_str + 2, conv_str + 2);
	// free(conv_str);
	return (final_str);
}

//TODO i
//TODO u
//TODO *
//TODO malloc protection
//TODO error handling
//TODO norm
//TODO fix segfault when a conversion fails


// precision applies to:
// d
// x
// X
// p
// u
// i
// o