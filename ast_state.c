/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:14:00 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 21:18:38 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ast_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->field_width = va_arg(ap, unsigned long long);
	(void)token;
}

void prec_ast_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->precision = va_arg(ap, unsigned long long);
	(void)token;
}