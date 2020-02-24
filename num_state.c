/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:38 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/24 12:41:28 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void num_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->field_width = (token - 48);
	(void)ap;
	// printf("num current token: %c, arg: %zu\n", token, (*arg)->field_width);
}

void num_repeat_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->field_width *= 10;
	(*arg)->field_width += (token - 48);
	(void)ap;
	// printf("num REPEAT current token: %c, arg: %zu\n", token, (*arg)->field_width);
}

void prec_num_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->precision = (token - 48);
	(void)ap;
	// printf("precision current token: %c, arg: %zu\n", token, (*arg)->precision);
}

void prec_num_repeat_state(char token, t_printf_arg **arg, va_list ap)
{
	(*arg)->precision *= 10;
	(*arg)->precision += (token - 48);
	(void)ap;
	// printf("precision REPEAT current token: %c, arg: %zu\n", token, (*arg)->precision);
}

