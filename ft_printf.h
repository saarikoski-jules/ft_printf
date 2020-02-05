/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/05 17:55:36 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>//
# include "libft/libft.h"

typedef union	u_type
{
	int				d;
	int				i;
	unsigned int	u;
	char			c;
	char			*s;
	unsigned int	x;
	unsigned int	X;
	void			*p;
}				t_type;

//unsigned ints for hex for sure

typedef enum	e_conversion
{
	d,
	i,
	u,
	c,
	s,
	x,
	X,
	p,
}				t_conversion;

typedef enum	e_padding
{
	p_normal,
	p_zero,
	p_left,
}				t_padding;

typedef struct	s_printf_arg
{
	t_conversion			conv;
	t_type					arg;
	t_padding				pad_type;
	unsigned int			field_width;
	// unsigned int			width; //should i use size_t?
	char					*format_str;
	struct s_printf_arg		*next;
}				t_printf_arg;

char	*ft_itoa_base(int n, int base);
// void	parse_current(t_transition_code state(char), char token, t_printf_arg **arg);
void	manage_parser(t_printf_arg **arg, char *tokens);

typedef	enum	e_transition_code
{
	t_dash,
	t_zero,
	t_num,
	t_error,
	t_exit,
}				t_transition_code;

//I can do this
t_transition_code entry_state(char token, t_printf_arg **arg);
t_transition_code dash_state(char token, t_printf_arg **arg);
t_transition_code zero_state(char token, t_printf_arg **arg);
t_transition_code num_state(char token, t_printf_arg **arg);
t_transition_code num_dash_state(char token, t_printf_arg **arg);
t_transition_code error_state(char token, t_printf_arg **arg);
t_transition_code error_dash_state(char token, t_printf_arg **arg);
t_transition_code exit_state(char token, t_printf_arg **arg);


t_transition_code get_transition_code(char token);
// t_transition_code (*function_ptrs[])(char) =
// {
// 	entry_state,
// 	dash_state,
// 	zero_state,
// 	num_state,
// 	num_dash_state,
// 	error_state,
// 	error_dash_state,
// 	exit_state,c
// };

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
	t_transition_code	(*orig_state)(char, t_printf_arg **);
	t_transition_code	transition;
	t_transition_code	(*next_state)(char, t_printf_arg **);
}				t_transition_obj;

// make sure if you've ever been to a dash_state, you'll never be able to enter a zero_state

static t_transition_obj const transition_table[] =
{
	{entry_state, t_dash, dash_state},
	{entry_state, t_zero, zero_state},
	{entry_state, t_num, num_state},
	{entry_state, t_error, error_state},
	{entry_state, t_exit, exit_state},

	{dash_state, t_dash, dash_state},
	{dash_state, t_zero, dash_state},
	{dash_state, t_num, num_dash_state},
	{dash_state, t_error, error_dash_state},
	{dash_state, t_exit, exit_state},

	{num_dash_state, t_dash, dash_state},
	{num_dash_state, t_zero, num_dash_state},
	{num_dash_state, t_num, num_dash_state},
	{num_dash_state, t_error, error_dash_state},
	{num_dash_state, t_exit, exit_state},

	{error_dash_state, t_dash, dash_state},
	{error_dash_state, t_zero, dash_state},
	{error_dash_state, t_num, num_dash_state}, //overwrite
	{error_dash_state, t_error, error_dash_state},
	{error_dash_state, t_exit, exit_state},

	{zero_state, t_dash, dash_state},
	{zero_state, t_zero, zero_state},
	{zero_state, t_num, num_state},
	{zero_state, t_error, error_state},
	{zero_state, t_exit, exit_state},

	{num_state, t_dash, num_state}, //undefined behavior in real printf
	{num_state, t_zero, num_state},
	{num_state, t_num, num_state},
	{num_state, t_error, error_state},
	{num_state, t_exit, exit_state},

	{error_state, t_dash, dash_state},
	{error_state, t_zero, zero_state},
	{error_state, t_num, num_state}, //previous num overwritten
	{error_state, t_error, error_state},
	{error_state, t_exit, exit_state},
};


#endif

// cspdiuxX%