/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 22:29:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/24 12:41:20 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prec_state(char token, t_printf_arg **arg, va_list ap)
{
	// printf("precision\n");
	(void)token;
	(void)ap;
	(*arg)->precision = 0;
	// if ((*arg)->pad_type == p_zero)
		// (*arg)->pad_type = p_normal;
}