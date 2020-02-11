/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 11:37:29 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 18:36:49 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_printf_arg *arg, char **str)
{
	*str = ft_strjoinchar(*str, arg->arg.c);
}
