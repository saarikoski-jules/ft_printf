/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dash_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 12:11:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/05 16:28:15 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_transition_code dash_state(char token, t_printf_arg **arg)
{
	printf("dash\n");
	(*arg)->pad_type = p_left;
	return (get_transition_code(token));
}
