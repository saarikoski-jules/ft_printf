/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:56 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 21:12:32 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void entry_state(char token, t_printf_arg **arg, va_list ap)
{
	// printf("enter\n");//
	(void)token;
	(void)(*arg);
	(void)ap;
}

void exit_state(char token, t_printf_arg **arg, va_list ap)
{
	// printf("exit\n");
	(void)token;
	(void)(*arg);
	(void)ap;
}
