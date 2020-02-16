/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_fw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 15:27:26 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:34:23 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_fw(t_printf_arg *arg)
{
	char *new;
	size_t	i;
	char 	c;

	new = (char *)ft_calloc(arg->field_width, sizeof(char));
	i = 0;
	if (arg->pad_type == p_normal || arg->pad_type == p_left)
		c = ' ';
	else if (arg->pad_type == p_zero)
		c = '0';
	while (i < arg->field_width)
	{
		new[i] = c;
		i++; 
	}
	return (new);
}