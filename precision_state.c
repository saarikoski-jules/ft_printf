/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 22:29:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 11:56:57 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prec_state(char token, t_printf_arg **arg)
{
	// printf("precision\n");
	(void)token;
	(*arg)->precision = 0;
	// printf("%zu\n", (*arg)->precision);
}