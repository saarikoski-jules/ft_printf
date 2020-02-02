#include "ft_printf.h"
#include <stdio.h>
// Next step: write a fucking parser
// States are function pointers that store information into a struct
// You read a token and enter that into a fsm
// State function will return a return code according to which you will transition to next state

// each state function has a corresponding state code (do i have to do this?)

// Can i recycle each token, aka if the same token exists multiple times in a row, handle it automatically without having to add it to the transition matrix

// Error state tokens are ignored

// t_transition_code 
typedef	enum	e_transition_code
{
	dash,
	zero,
	num,
	error,
	exit,
}				t_transition_code;

t_transition_code entry_state(char token)
{
	printf("enter\n");
	return (dash);
}

t_transition_code dash_state(char token)
{
	printf("dash\n");
	return (exit);
}
// t_transition_code zero_state(char token);
// t_transition_code num_state(char token);
// t_transition_code num_dash_state(char token);
// t_transition_code error_state(char token);
// t_transition_code error_dash_state(char token);
t_transition_code exit_state(char token)
{
	printf("exit\n");
	return (exit);
}

//I can do this

t_transition_code (*function_ptrs[])(char) =
{
	entry_state,
	dash_state,
	// zero_state,
	// num_state,
	// num_dash_state,
	// error_state,
	// error_dash_state,
	exit_state,
};

// Will I have to access function poiners by using indexing? Should I use a state code enum for this instead?

// typedef enum	e_state_code
// {
// 	entry_state,
// 	dash_state,
// 	zero_state,
// 	num_state,
// 	num_dash_state,
// 	error_dash_state,
// 	error_state,
// 	exit_state,
// }				t_state_code;

// Or this?

// typedef t_transition_code (*state_func)(char); // pointer in (*state_func)

// static state_func function_ptrs[] = // or before *function_ptrs
// {
// 	entry_state,
// 	dash_state,
// 	zero_state,
// 	num_state,
// 	num_dash_state,
// 	error_state,
// 	error_dash_state,
// 	exit_state,
// };

typedef struct s_transition_obj
{
	t_transition_code	(*orig_state)(char);
	t_transition_code	transition;
	t_transition_code	(*next_state)(char);
}				t_transition_obj;

// make sure if you've ever been to a dash_state, you'll never be able to enter a zero_state

static t_transition_obj const transition_table[] =
{
	{entry_state, dash, dash_state},
	// {entry_state, zero, zero_state},
	// {entry_state, num, num_state},
	// {entry_state, error, error_state},
	// {entry_state, exit, exit_state},

	// {dash_state, dash, dash_state},
	// {dash_state, zero, dash_state},
	// {dash_state, num, num_dash_state},
	// {dash_state, error, error_dash_state},
	{dash_state, exit, exit_state},

	// {num_dash_state, dash, dash_state},
	// {num_dash_state, zero, num_dash_state},
	// {num_dash_state, num, num_dash_state},
	// {num_dash_state, error, error_dash_state},
	// {num_dash_state, exit, exit_state},

	// {error_dash_state, dash, dash_state},
	// {error_dash_state, zero, dash_state},
	// {error_dash_state, num, num_dash_state}, //overwrite
	// {error_dash_state, error, error_dash_state},
	// {error_dash_state, exit, exit_state},

	// {zero_state, dash, dash_state},
	// {zero_state, zero, zero_state},
	// {zero_state, num, num_state},
	// {zero_state, error, error_state},
	// {zero_state, exit, exit_state},

	// {num_state, dash, num_state}, //undefined behavior in real printf
	// {num_state, zero, num_state},
	// {num_state, num, num_state},
	// {num_state, error, error_state},
	// {num_state, exit, exit_state},

	// {error_state, dash, dash_state},
	// {error_state, zero, zero_state},
	// {error_state, num, num_state}, //previous num overwritten
	// {error_state, error, error_state},
	// {error_state, exit, exit_state},
};

t_transition_code parse_current(t_transition_code state(char), char token, t_printf_arg **arg)
{
	// printf("%c\n", token);
	return (state(token));
}

void manage_parser(t_printf_arg **arg, char *tokens)
{
	// char current_token;
	int i;
	int j;
	t_transition_code (*state)(char);
	t_transition_code transition;
	state = &entry_state;

	i = 0;
	while (tokens[i] != '\0')
	{
		// printf("loop\n");
		j = 0;
		printf("%u\n", transition);
		transition = parse_current(state, tokens[i], arg);
		// find the item in transition table that has the current state and the current transition
		// iterate over the transition table and check for orig state and transition values
		// state = (&transition_table)->next_state;
		while(&transition_table[j])
		{
			if ((&transition_table[j])->orig_state == state && ((&transition_table[j])->transition) == transition)
			{
				state = ((&transition_table[j])->next_state);
				break ;
			}
			j++;
		}
		i++;
	}
	// parse_current(state, tokens[i], arg);

	//keep track of current state
	//retrieve transition code

	// parser(current_token);
}
