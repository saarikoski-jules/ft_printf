/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/01/17 19:24:10 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef union	u_type
{
	int		d;
	int		i;
	char	c;
	char	*s;
}				t_type;

typedef enum	e_kind
{
	d,
	i,
	c,
	s,
}				t_kind;

typedef struct	s_printf_arg
{
	t_type					arg;
	struct s_printf_arg		*next;
}				t_printf_arg;

#endif

// cspdiuxX%