/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 16:22:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/10 16:45:40 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*get_next_state(void (*prev_state)(char, t_printf_arg **),
							t_transition_code transition)
{
	int	i;

	i = 0;
	while (&transition_table[i])
	{
		if ((&transition_table[i])->orig_state == prev_state &&
			(&transition_table[i])->transition == transition)
			return ((&transition_table[i])->next_state);
		i++;
	}
	return (error_state);
}

void		manage_parser(t_printf_arg **arg, char *tokens)
{
	void				(*state)(char, t_printf_arg **);
	t_transition_code	transition;
	int					i;

	i = 0;
	state = &entry_state;
	while (tokens[i] != '\0')
	{
		transition = get_transition(tokens[i]);
		state = get_next_state(state, transition);
		state(tokens[i], arg);
		i++;
	}
}
