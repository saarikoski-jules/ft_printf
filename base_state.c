/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:56 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/05 16:24:17 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_transition_code entry_state(char token, t_printf_arg **arg)
{
	printf("enter\n");//
	return (get_transition_code(token));
}

t_transition_code exit_state(char token, t_printf_arg **arg)
{
	printf("exit\n");
	return (t_exit);
}
