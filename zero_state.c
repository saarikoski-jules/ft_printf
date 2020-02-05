/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:48 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/05 18:53:33 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_transition_code zero_state(char token, t_printf_arg **arg)
{
	printf("zero, token %c ... ", token);
	(*arg)->pad_type = p_zero;
	t_transition_code cur = get_transition_code(token);
	printf("cur: %d\n", cur);
	return (get_transition_code(token));
}
