#include "ft_printf.h"
// Next step: write a fucking parser
// States are function pointers that store information into a struct
// You read a token and enter that into a fsm
// State function will return a return code according to which you will transition to next state

// each state function has a corresponding state code (do i have to do this?)

// Can i recycle each token, aka if the same token exists multiple times in a row, handle it automatically without having to add it to the transition matrix

// Error state tokens are ignored

// t_transition_code 

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
typedef	enum	e_transition_code
{
	dash,
	zero,
	num,
	error,
	exit,
}				t_transition_code;

typedef t_transition_code (*state_func)(char); // pointer in (*state_func)

t_transition_code entry_state(char token);
t_transition_code dash_state(char token);
t_transition_code zero_state(char token);
t_transition_code num_state(char token);
t_transition_code num_dash_state(char token);
t_transition_code error_state(char token);
t_transition_code error_dash_state(char token);
t_transition_code exit_state(char token);


static state_func function_ptrs[] = // or before *function_ptrs
{
	entry_state,
	dash_state,
	zero_state,
	num_state,
	num_dash_state,
	error_state,
	error_dash_state,
	exit_state,
};

typedef struct s_transition_obj
{
	t_transition_code	orig_state;
	t_transition_code	transition;
	t_transition_code	next_state;
}				t_transition_obj;

// make sure if you've ever been to a dash_state, you'll never be able to enter a zero_state

static t_transition_obj const transition_table[] =
{
	{entry_state, dash, dash_state},
	{entry_state, zero, zero_state},
	{entry_state, num, num_state},
	{entry_state, error, error_state},
	{entry_state, exit, exit_state},

	{dash_state, dash, dash_state},
	{dash_state, zero, dash_state},
	{dash_state, num, num_dash_state},
	{dash_state, error, error_dash_state},
	{dash_state, exit, exit_state},

	{num_dash_state, dash, dash_state},
	{num_dash_state, zero, num_dash_state},
	{num_dash_state, num, num_dash_state},
	{num_dash_state, error, error_dash_state},
	{num_dash_state, exit, exit_state},

	{error_dash_state, dash, dash_state},
	{error_dash_state, zero, dash_state},
	{error_dash_state, num, num_dash_state}, //overwrite
	{error_dash_state, error, error_dash_state},
	{error_dash_state, exit, exit_state},

	{zero_state, dash, dash_state},
	{zero_state, zero, zero_state},
	{zero_state, num, num_state},
	{zero_state, error, error_state},
	{zero_state, exit, exit_state},

	{num_state, dash, num_state}, //undefined behavior in real printf
	{num_state, zero, num_state},
	{num_state, num, num_state},
	{num_state, error, error_state},
	{num_state, exit, exit_state},

	{error_state, dash, dash_state},
	{error_state, zero, zero_state},
	{error_state, num, num_state}, //previous num overwritten
	{error_state, error, error_state},
	{error_state, exit, exit_state},
};

void manage_parser(t_printf_arg **arg, char *tokens)
{
	// char current_token;
	int i;

	i = 0;
	while (tokens[i] != '\0')
	{
		
	}
	//keep track of current state
	//retrieve transition code

	// parser(current_token);
}
