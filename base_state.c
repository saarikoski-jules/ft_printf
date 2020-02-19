/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:56 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 11:58:23 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void entry_state(char token, t_printf_arg **arg)
{
	// printf("enter\n");//
	(void)token;
	(void)(*arg);
	// (*arg)->pad_type = p_normal;
	// (*arg)->field_width = 0;
	// (*arg)->precision = 0;
}

void exit_state(char token, t_printf_arg **arg)
{
	(void)token;
	(void)(*arg);
	// printf("exit\n");
}
