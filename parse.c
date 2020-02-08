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


// t_transition_code parse_current(t_transition_code state(char, t_printf_arg **), char token, t_printf_arg **arg)
// {
// 	// printf("in parse current:\ntoken: %c\ncurrent state: %d\n", token, state);
// 	return (state(token, arg));
// }

// void manage_parser(t_printf_arg **arg, char *tokens)
// {
// 	// char current_token;
// 	int i;
// 	int j;
// 	t_transition_code (*state)(char, t_printf_arg **);
// 	t_transition_code transition;
// 	state = &entry_state;
// 	transition = parse_current(state, tokens[0], arg);

// 	// printf("%d\n", transition);
// 	i = 0;
// 	while (tokens[i] != '\0')
// 	{
// 		// printf("%c\n", tokens[i]);
// 		j = 0;
// 		// find the item in transition table that has the current state and the current transition
// 		// iterate over the transition table and check for orig state and transition values
// 		// state = (&transition_table)->next_state;
// 		while (&transition_table[j])
// 		{
// 			if (state == &exit_state)
// 				return ;
// 			if ((&transition_table[j])->orig_state == state && ((&transition_table[j])->transition) == transition)
// 			{
// 				state = (&transition_table[j])->next_state;
// 				break ;
// 			}
// 			j++;
// 		}
// 		printf("%c\n", tokens[i]);
// 		transition = parse_current(state, tokens[i], arg);
// 		// printf("transition: %u\n", transition);
// 		i++;
// 	}

// 	// parse_current(state, tokens[i], arg);

// 	//keep track of current state
// 	//retrieve transition code

// 	// parser(current_token);
// }

//Make a different parse manager. Get state transition in a separate function and always excecute state_next

t_transition_code get_transition(void state(char, t_printf_arg **), char token, t_printf_arg **arg)
{
	//Move this function up to call functions from and pass transition code to current state.
	//Or get next state from this function and call states independently <-- yess
	// printf("token: %c\n", token);
	// state(token, arg);

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

void manage_parser(t_printf_arg **arg, char *tokens)
{
	void				(*state)(char, t_printf_arg **);
	char				cur_token;
	t_transition_code	transition;
	int					i;
	int					j;

	i = 0;
	state = &entry_state;
	// transition = get_transition(state, tokens[i], arg);
	while(tokens[i] != '\0')
	{
		j = 0;
		transition = get_transition(state, tokens[i], arg);
		printf("round: %d, token: %c, transition %d\n", i, tokens[i], transition);
		while(&transition_table[j])
		{
			if (state == &exit_state)
				return ;
			if ((&transition_table[j])->orig_state == state && (&transition_table[j])->transition == transition)
			{
				state = (&transition_table[j])->next_state;
				break;
			}
			j++;
		}
		state(tokens[i], arg);
		i++;
	}
}



// t_transition_code get_transition_code(char token)
// {
// 	//Move this function up to call functions from and pass transition code to current state.
// 	//Or get next state from this function and call states independently <-- yess
// 	// printf("token: %c\n", token);
	

// 	if (token == '-')
// 		return (t_dash);
// 	else if (token == '0')
// 		return (t_zero);
// 	else if (token <= '9' && token >= '1')
// 		return (t_num);
// 	else if (token == '\0')
// 		return (t_exit);
// 	else
// 		return (t_error);
// }

// determines next state basced on the previous token.
// I should make a get next state function that will get states and assign data in the correct time