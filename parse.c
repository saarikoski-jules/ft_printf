#include "ft_printf.h"

// #include <stdio.h>
// Next step: write a fucking parser
// States are function pointers that store information into a struct
// You read a token and enter that into a fsm
// State function will return a return code according to which you will transition to next state

// each state function has a corresponding state code (do i have to do this?)

// Can i recycle each token, aka if the same token exists multiple times in a row, handle it automatically without having to add it to the transition matrix

// Error state tokens are ignored

// t_transition_code 


t_transition_code parse_current(t_transition_code state(char, t_printf_arg **), char token, t_printf_arg **arg)
{
	// printf("in parse current:\ntoken: %c\ncurrent state: %d\n", token, state);
	return (state(token, arg));
}

void manage_parser(t_printf_arg **arg, char *tokens)
{
	// char current_token;
	int i;
	int j;
	t_transition_code (*state)(char, t_printf_arg **);
	t_transition_code transition;
	state = &entry_state;
	transition = parse_current(state, tokens[i], arg);
	printf("%d\n", transition);
	i = 0;
	while (tokens[i] != '\0')
	{
		printf("%c\n", tokens[i]);
		j = 0;
		// find the item in transition table that has the current state and the current transition
		// iterate over the transition table and check for orig state and transition values
		// state = (&transition_table)->next_state;
		while (&transition_table[j])
		{
			if (state == &exit_state)
				return ;
			if ((&transition_table[j])->orig_state == state && ((&transition_table[j])->transition) == transition)
			{
				state = (&transition_table[j])->next_state;
				break ;
			}
			j++;
		}
		transition = parse_current(state, tokens[i], arg);
		i++;
	}

	// parse_current(state, tokens[i], arg);

	//keep track of current state
	//retrieve transition code

	// parser(current_token);
}

t_transition_code get_transition_code(char token)
{
	if (token == '-')
		return (t_dash);
	else if (token == '0')
		return (t_zero);
	else if (token <= '9' && token >= '1')
		return (t_num);
	else if (token == '\0')
		return (t_exit);
	else
		return (t_error);
}