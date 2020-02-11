/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 18:22:06 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 18:23:35 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_str(t_printf_arg *arg, char **str)
{
	*str = ft_strjoin(arg->arg.s, *str);
}