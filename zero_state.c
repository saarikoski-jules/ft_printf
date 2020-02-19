/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:48 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 16:19:26 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void zero_state(char token, t_printf_arg **arg)
{
	if ((*arg)->pad_type != p_left)
		(*arg)->pad_type = p_zero;
	(void)token;
}
