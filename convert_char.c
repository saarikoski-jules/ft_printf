/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:37:29 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/04 12:45:25 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_char(t_printf_arg **arg)
{
	char *new;


	new = (char *)ft_calloc(2, sizeof(char));//
	if (!new)
		return (NULL);
	new[0] = (*arg)->arg.c;
	(*arg)->arg_width = 1;
	// ft_memcpy(new, arg->arg.c, 1);
	// printf("\nconvert char: '%d', strlen: %d\n", new[0], ft_strlen(new));
	// (void)arg->arg.c;
	return (new);





	// char *new;
	
	// // printf("\n\npad type: %d\n\n", arg->pad_type);
	// // printf("\n\nprec: %d, strlen: %d\n\n", arg->precision, ft_strlen(arg->arg.s));
	// if (arg->precision < 1)
	// {
	// 	// printf("goes hereee\n");
	// 	new = (char *)ft_calloc(arg->precision + 1, sizeof(char));
	// 	if (!new)
	// 		return (NULL);
		
	// 	ft_strlcpy(new, arg->arg.s, arg->precision + 1);
	// }
	// else
	// 	new = (char *)ft_calloc(2, sizeof(char));
	// 	new[0] = arg->arg.c;//
	// if (!new)
	// 	return (NULL);
	// return (new);
}

// TODO Modulo!!