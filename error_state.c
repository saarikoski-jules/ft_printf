/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:02:01 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/05 16:29:00 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_transition_code error_state(char token, t_printf_arg **arg)
{
	printf("error\n");
	return (get_transition_code(token));
}

t_transition_code error_dash_state(char token, t_printf_arg **arg)
{
	printf("error dash\n");
	return (get_transition_code(token));
}