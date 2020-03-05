/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 17:09:16 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>//
# include <unistd.h>//
# include <stdarg.h>//
# include "libft/libft.h"

/*
**	FINITE STATE MACHINE
*/

// typedef union	u_type
// {
// 	int				d;
// 	int				i;
// 	unsigned int	u;
// 	char			c;
// 	char			*s;
// 	unsigned int	x;
// 	unsigned int	X;
// 	void			*p;
// }				t_type;

typedef union	u_type
{
	long long			i;
	unsigned long long	u;
	char				c;
	char				*s;
	unsigned long long	p;
}				t_type;

// Should I make everything that's the same data type one thing? Would make the rest of my code easier as well
//unsigned ints for hex for sure (Or unsifned long??)

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
	size_t					arg_width;
	ssize_t					precision;
	struct s_printf_arg		*next;
}				t_printf_arg;

typedef	enum	e_transition_code
{
	t_dash,
	t_zero,
	t_num,
	t_dot,
	t_ast,
	t_error,
	t_exit,
}				t_transition_code;

/*
**	STATES
*/



void entry_state(char token, t_printf_arg **arg, va_list ap);
void dash_state(char token, t_printf_arg **arg, va_list ap);
void zero_state(char token, t_printf_arg **arg, va_list ap);
void num_state(char token, t_printf_arg **arg, va_list ap);
void num_repeat_state(char token, t_printf_arg **arg, va_list ap);
void prec_state(char token, t_printf_arg **arg, va_list ap);
void prec_num_state(char token, t_printf_arg **arg, va_list ap);
void prec_num_repeat_state(char token, t_printf_arg **arg, va_list ap);
void ast_state(char token, t_printf_arg **arg, va_list ap);
void prec_ast_state(char token, t_printf_arg **arg, va_list ap);
void error_state(char token, t_printf_arg **arg, va_list ap);
void exit_state(char token, t_printf_arg **arg, va_list ap);

// typedef void (*state_ptr)(char, t_printf_arg **, va_list);

t_transition_code get_transition_code(char token);

typedef struct s_transition_obj
{
	void				(*orig_state)(char, t_printf_arg **, va_list);
	t_transition_code	transition;
	void				(*next_state)(char, t_printf_arg **, va_list);
}				t_transition_obj;

static t_transition_obj const transition_table[] =
{
	{entry_state, t_dash, dash_state},
	{entry_state, t_zero, zero_state},
	{entry_state, t_num, num_state},
	{entry_state, t_ast, ast_state},
	{entry_state, t_dot, prec_state},
	{entry_state, t_error, error_state},
	{entry_state, t_exit, exit_state},

	{dash_state, t_dash, dash_state},
	{dash_state, t_zero, dash_state},
	{dash_state, t_num, num_state},
	{dash_state, t_ast, ast_state},
	{dash_state, t_dot, prec_state},
	{dash_state, t_error, error_state},
	{dash_state, t_exit, exit_state},

	{zero_state, t_dash, dash_state},
	{zero_state, t_zero, zero_state},
	{zero_state, t_num, num_state},
	{zero_state, t_ast, ast_state},
	{zero_state, t_dot, prec_state},
	{zero_state, t_error, error_state},
	{zero_state, t_exit, exit_state},

	{num_state, t_dash, dash_state}, //undefined behavior in real printf
	{num_state, t_zero, num_repeat_state},
	{num_state, t_num, num_repeat_state},
	{num_state, t_ast, ast_state},
	{num_state, t_dot, prec_state},
	{num_state, t_error, error_state},
	{num_state, t_exit, exit_state},

	{num_repeat_state, t_dash, dash_state},
	{num_repeat_state, t_zero, num_repeat_state},
	{num_repeat_state, t_num, num_repeat_state},
	{num_repeat_state, t_ast, ast_state},
	{num_repeat_state, t_dot, prec_state},
	{num_repeat_state, t_error, error_state},
	{num_repeat_state, t_exit, exit_state},

	{ast_state, t_dash, dash_state},
	{ast_state, t_zero, zero_state},
	{ast_state, t_num, num_state},
	{ast_state, t_ast, ast_state},
	{ast_state, t_dot, prec_state},
	{ast_state, t_error, error_state},
	{ast_state, t_exit, exit_state},

	{prec_ast_state, t_dash, dash_state},
	{prec_ast_state, t_zero, zero_state},
	{prec_ast_state, t_num, num_state},
	{prec_ast_state, t_ast, ast_state},
	{prec_ast_state, t_dot, prec_state},
	{prec_ast_state, t_error, error_state},
	{prec_ast_state, t_exit, exit_state},

	{prec_state, t_dash, dash_state},
	{prec_state, t_zero, prec_num_state},
	{prec_state, t_num, prec_num_state},
	{prec_state, t_ast, prec_ast_state},
	{prec_state, t_dot, prec_state}, //undefined behavior
	{prec_state, t_error, error_state},
	{prec_state, t_exit, exit_state},

	{prec_num_state, t_dash, dash_state},
	{prec_num_state, t_zero, prec_num_repeat_state},
	{prec_num_state, t_num, prec_num_repeat_state},
	{prec_num_state, t_ast, prec_ast_state},
	{prec_num_state, t_dot, prec_state},
	{prec_num_state, t_error, error_state},
	{prec_num_state, t_exit, exit_state},

	{prec_num_repeat_state, t_dash, dash_state},
	{prec_num_repeat_state, t_zero, prec_num_repeat_state},
	{prec_num_repeat_state, t_num, prec_num_repeat_state},
	{prec_num_repeat_state, t_ast, prec_ast_state},
	{prec_num_repeat_state, t_dot, prec_state},
	{prec_num_repeat_state, t_error, error_state},
	{prec_num_repeat_state, t_exit, exit_state},

	{error_state, t_dash, dash_state},
	{error_state, t_zero, zero_state},
	{error_state, t_num, num_state}, //previous num overwritten
	{error_state, t_ast, ast_state}, //previous num overwritten
	{error_state, t_dot, prec_state},
	{error_state, t_error, error_state},
	{error_state, t_exit, exit_state},

};

int					ft_printf(const char *str, ...);
void				manage_parser(t_printf_arg **arg, char *tokens, va_list ap);
t_transition_code	get_transition(char token);
int					manage_print(const char *str, t_printf_arg **head);
char				*execute_arg(t_printf_arg **cur_arg);
int	gen_arg_list(t_printf_arg **head, const char *str, va_list ap);


char				*convert_char(t_printf_arg **arg);
char				*convert_int(t_printf_arg **arg);
char				*convert_uint(t_printf_arg **arg);
// char				*convert_iint(t_printf_arg *arg);
char				*convert_str(t_printf_arg **arg);
char				*convert_hex_lc(t_printf_arg **arg);
char *convert_hex_uc(t_printf_arg **arg);
char *convert_ptr(t_printf_arg **arg);


void clear_list(t_printf_arg **head);
char *fill_buffer(t_printf_arg **arg, char *conv_str);
void cpy_from(char **final, char *conv, int index);
void add_conv(char **final, char *conv, t_printf_arg **arg);
char *apply_precision(t_printf_arg **arg, char *str);
void store_int(char c, t_printf_arg **cur, va_list ap);
void store_uint(char c, t_printf_arg **cur, va_list ap);
void store_char(char c, t_printf_arg **cur, va_list ap);
int store_other(char c, t_printf_arg **cur, va_list ap);

#endif

