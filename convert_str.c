/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 18:22:06 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/25 11:46:24 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_str(t_printf_arg **arg)
{
	char *new;
	
	// printf("\n\npad type: %d\n\n", arg->pad_type);
	// printf("\n\nprec: %d, strlen: %d\n\n", arg->precision, ft_strlen(arg->arg.s));
	if ((*arg)->precision < ft_strlen((*arg)->arg.s))
	{
		// printf("goes hereee\n");
		new = (char *)ft_calloc((*arg)->precision + 1, sizeof(char));
		if (!new)
			return (NULL);
		ft_strlcpy(new, (*arg)->arg.s, (*arg)->precision + 1);
	}
	else
		new = ft_strdup((*arg)->arg.s);//
	if (!new)
		return (NULL);
		(*arg)->arg_width = ft_strlen(new);
	return (new);
}