/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:25:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:42:25 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef char *(*func)(t_printf_arg *);

func choose_converter(t_printf_arg *cur_arg)
{

	if (cur_arg->conv == c)
	{
		return (convert_char);
		// func = &convert_char;
		// printf("cccc\n");
		// convert_char(cur_arg, str);
	}
	else if (cur_arg->conv == d)
	{
		return (convert_int);
		// convert_int(cur_arg, str);
	}
	else if (cur_arg->conv == s)
		return (convert_str);
	else if (cur_arg->conv == x)
		return (convert_hex_lc);
	else if (cur_arg->conv == X)
		return (convert_hex_uc);
	else if (cur_arg->conv == p)
		return (convert_ptr);

	return (convert_ptr);
	// printf("string is: %s\n", *str);
	
}

char *execute_arg(t_printf_arg *arg)
{
	char			*tmp;
	// char			*final_str;
	char			*conv_str;
	func	conv;

	tmp = NULL;
	// tmp = ft_strdup("");
	tmp = apply_fw(arg);
	conv = choose_converter(arg);
	conv_str = conv(arg);

	//convert item to string
	//Separate function for appending strings the correct way

	printf("\n\nFILLED MAIN STR: %s\nCONVERSION STR %s\n\n", conv_str, tmp);

	free(tmp);
	return (conv_str);
}

//TODO i
//TODO u
