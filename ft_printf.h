/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:02:19 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/01 17:37:20 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

typedef struct	s_printf_arg
{
	t_conversion			conv;
	t_type					arg;
	// unsigned int			width; //should i use size_t?
	char					*format_str;
	struct s_printf_arg		*next;
}				t_printf_arg;

char	*ft_itoa_base(int n, int base);

#endif

// cspdiuxX%