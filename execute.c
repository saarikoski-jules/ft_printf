/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:25:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/13 18:17:11 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void choose_converter(t_printf_arg *cur_arg, char **str)
{
	if (cur_arg->conv == c)
	{
		// printf("cccc\n");
		convert_char(cur_arg, str);
	}
	else if (cur_arg->conv == d)
		convert_int(cur_arg, str);
	else if (cur_arg->conv == s)
		convert_str(cur_arg, str);
	else if (cur_arg->conv == x)
		convert_hex_lc(cur_arg, str);
	else if (cur_arg->conv == X)
		convert_hex_uc(cur_arg, str);
	else if (cur_arg->conv == p)
		convert_ptr(cur_arg, str);
	
	// printf("string is: %s\n", *str);
	
}

char *execute_arg(t_printf_arg *arg)
{
	char			*str;

	str = ft_strdup("");
	choose_converter(arg, &str);
	return (str);
}

//TODO i
//TODO u
