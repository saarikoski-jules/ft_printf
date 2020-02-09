/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 22:29:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/09 22:54:39 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void prec_state(char token, t_printf_arg **arg)
{
	printf("precision\n");
	(*arg)->precision = 0;
}