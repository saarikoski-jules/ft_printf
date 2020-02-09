/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:48 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/09 20:56:30 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void zero_state(char token, t_printf_arg **arg)
{
	printf("zero, token %c\n", token);
	if ((*arg)->pad_type != p_left)
		(*arg)->pad_type = p_zero;
	// t_transition_code cur = get_transition_code(token);
	// printf("cur: %d\n", cur);
}
