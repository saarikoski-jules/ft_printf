/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:25:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 18:43:24 by jsaariko      ########   odam.nl         */
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

void print_arg_str(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		printf("index: %d, current char: '%c'\n", i, str[i]);
		i++;
	}
}

char *execute_arg(t_printf_arg *arg)
{
	// char	*tmp;
	char	*final_str;
	char	*conv_str;
	func	conv;

	final_str = NULL;
	// tmp = ft_strdup("");
	conv = choose_converter(arg);
	conv_str = conv(arg);
	final_str = apply_fw(arg, conv_str);
	// print_arg_str(final_str);

	add_conv(&final_str, conv_str, arg);

	// print_arg_str(final_str);

	//Separate function for appending strings the correct way

	// printf("\nCONV: '%s'\nFINAL '%s'\n", conv_str, final_str);
	printf("'%s'\n", final_str);

	free(conv_str);
	return (final_str);
}

//TODO i
//TODO u
