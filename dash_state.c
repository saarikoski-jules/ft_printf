/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dash_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 12:11:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/08 22:24:28 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void dash_state(char token, t_printf_arg **arg)
{
	printf("dash\n");
	(*arg)->pad_type = p_left;
}
