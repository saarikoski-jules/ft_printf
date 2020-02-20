/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:02:01 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 16:32:50 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void error_state(char token, t_printf_arg **arg, va_list ap)
{
	// printf("error\n");
	(void)token;
	(void)(*arg);
	(void)ap;
}
