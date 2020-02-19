/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:37:29 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:03:00 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_char(t_printf_arg *arg)
{
	char *new;

	new = (char *)ft_calloc(2, sizeof(char));//
	if (!new)
		return (NULL);
	new[0] = arg->arg.c;
	return (new);
}