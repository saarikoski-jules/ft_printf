/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:38 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/08 22:23:06 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void num_state(char token, t_printf_arg **arg)
{
	printf("current num: %c\n", token);
	if (!(*arg)->field_width)
		(*arg)->field_width += (token - 48);
	else
		(*arg)->field_width *= 10 + (token - 48);
}

void num_dash_state(char token, t_printf_arg **arg)
{
	printf("(dash) current num: %c\n", token);
	if (!(*arg)->field_width)
		(*arg)->field_width += (token - 48);
	else
		(*arg)->field_width *= 10 + (token - 48);

}
