/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 21:00:15 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>//
# include "libft.h"

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
	size_t					field_width;
	size_t					precision;
	// char					*str;
	struct s_printf_arg		*next;
}				t_printf_arg;


typedef	enum	e_transition_code
{
	t_dash,
	t_zero,
	t_num,
	t_dot,
	t_error,
	t_exit,
}				t_transition_code;

//I can do this
void entry_state(char token, t_printf_arg **arg);
void dash_state(char token, t_printf_arg **arg);
void zero_state(char token, t_printf_arg **arg);
void num_state(char token, t_printf_arg **arg);
void num_repeat_state(char token, t_printf_arg **arg);
void prec_state(char token, t_printf_arg **arg);
void prec_num_state(char token, t_printf_arg **arg);
void prec_num_repeat_state(char token, t_printf_arg **arg);
// void num_dash_state(char token, t_printf_arg **arg);
void error_state(char token, t_printf_arg **arg);
// void error_dash_state(char token, t_printf_arg **arg);
void exit_state(char token, t_printf_arg **arg);


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
	void				(*orig_state)(char, t_printf_arg **);
	t_transition_code	transition;
	void				(*next_state)(char, t_printf_arg **);
}				t_transition_obj;

// make sure if you've ever been to a dash_state, you'll never be able to enter a zero_state

// static t_transition_obj const transition_table[] =
// {
// 	{entry_state, t_dash, dash_state},
// 	{entry_state, t_zero, zero_state},
// 	{entry_state, t_num, num_state},
// 	{entry_state, t_error, error_state},
// 	{entry_state, t_exit, exit_state},

// 	{dash_state, t_dash, dash_state},
// 	{dash_state, t_zero, dash_state},
// 	{dash_state, t_num, num_dash_state},
// 	{dash_state, t_error, error_dash_state},
// 	{dash_state, t_exit, exit_state},

// 	{num_dash_state, t_dash, dash_state},
// 	{num_dash_state, t_zero, num_dash_state},
// 	{num_dash_state, t_num, num_dash_state},
// 	{num_dash_state, t_error, error_dash_state},
// 	{num_dash_state, t_exit, exit_state},

// 	{error_dash_state, t_dash, dash_state},
// 	{error_dash_state, t_zero, dash_state},
// 	{error_dash_state, t_num, num_dash_state}, //overwrite
// 	{error_dash_state, t_error, error_dash_state},
// 	{error_dash_state, t_exit, exit_state},

// 	{zero_state, t_dash, dash_state},
// 	{zero_state, t_zero, zero_state},
// 	{zero_state, t_num, num_state},
// 	{zero_state, t_error, error_state},
// 	{zero_state, t_exit, exit_state},

// 	{num_state, t_dash, dash_state}, //undefined behavior in real printf
// 	{num_state, t_zero, num_state},
// 	{num_state, t_num, num_state},
// 	{num_state, t_error, error_state},
// 	{num_state, t_exit, exit_state},

// 	{error_state, t_dash, dash_state},
// 	{error_state, t_zero, zero_state},
// 	{error_state, t_num, num_state}, //previous num overwritten
// 	{error_state, t_error, error_state},
// 	{error_state, t_exit, exit_state},
// };

static t_transition_obj const transition_table[] =
{
	{entry_state, t_dash, dash_state},
	{entry_state, t_zero, zero_state},
	{entry_state, t_num, num_state},
	{entry_state, t_dot, prec_state},
	{entry_state, t_error, error_state},
	{entry_state, t_exit, exit_state},

	{dash_state, t_dash, dash_state},
	{dash_state, t_zero, dash_state},
	{dash_state, t_num, num_state},
	{dash_state, t_dot, prec_state},
	{dash_state, t_error, error_state},
	{dash_state, t_exit, exit_state},

	{zero_state, t_dash, dash_state},
	{zero_state, t_zero, zero_state},
	{zero_state, t_num, num_state},
	{zero_state, t_dot, prec_state},
	{zero_state, t_error, error_state},
	{zero_state, t_exit, exit_state},

	{num_state, t_dash, dash_state}, //undefined behavior in real printf
	{num_state, t_zero, num_repeat_state},
	{num_state, t_num, num_repeat_state},
	{num_state, t_dot, prec_state},
	{num_state, t_error, error_state},
	{num_state, t_exit, exit_state},

	{num_repeat_state, t_dash, dash_state},
	{num_repeat_state, t_zero, num_repeat_state},
	{num_repeat_state, t_num, num_repeat_state},
	{num_repeat_state, t_dot, prec_state},
	{num_repeat_state, t_error, error_state},
	{num_repeat_state, t_exit, exit_state},

	{prec_state, t_dash, dash_state},
	{prec_state, t_zero, zero_state},
	{prec_state, t_num, prec_num_state},
	{prec_state, t_dot, prec_state}, //undefined behavior
	{prec_state, t_error, error_state},
	{prec_state, t_exit, exit_state},

	{prec_num_state, t_dash, dash_state},
	{prec_num_state, t_zero, prec_num_repeat_state},
	{prec_num_state, t_num, prec_num_repeat_state},
	{prec_num_state, t_dot, prec_state},
	{prec_num_state, t_error, error_state},
	{prec_num_state, t_exit, exit_state},

	{prec_num_repeat_state, t_dash, dash_state},
	{prec_num_repeat_state, t_zero, prec_num_repeat_state},
	{prec_num_repeat_state, t_num, prec_num_repeat_state},
	{prec_num_repeat_state, t_dot, prec_state},
	{prec_num_repeat_state, t_error, error_state},
	{prec_num_repeat_state, t_exit, exit_state},

	{error_state, t_dash, dash_state},
	{error_state, t_zero, zero_state},
	{error_state, t_num, num_state}, //previous num overwritten
	{error_state, t_dot, prec_state},
	{error_state, t_error, error_state},
	{error_state, t_exit, exit_state},

};

int		ft_printf(const char *str, ...);
char	*ft_itoa_base(int n, int base);
// void	parse_current(t_transition_code state(char), char token, t_printf_arg **arg);
void	manage_parser(t_printf_arg **arg, char *tokens);
t_transition_code get_transition(char token);
int manage_print(const char *str, t_printf_arg **head);
char *execute_arg(t_printf_arg *cur_arg);
char *convert_char(t_printf_arg *arg);
char *convert_int(t_printf_arg *arg);
char *convert_str(t_printf_arg *arg);
char *convert_hex_lc(t_printf_arg *arg);
char *convert_hex_uc(t_printf_arg *arg);
char *convert_ptr(t_printf_arg *arg);
void clear_list(t_printf_arg **head);
// char *fill_buffer(t_printf_arg *arg, char *str);
char *fill_buffer(t_printf_arg *arg, char *conv_str);
void cpy_from(char **final, char *conv, int index);
void add_conv(char **final, char *conv, t_printf_arg *arg);
char *apply_precision(t_printf_arg *arg, char *str);
// void 

#endif

// cspdiuxX%