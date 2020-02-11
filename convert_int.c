/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:25:42 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 18:19:59 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void convert_int(t_printf_arg *arg, char **str)
{
	*str = ft_strjoin(ft_itoa(arg->arg.d), *str);
}