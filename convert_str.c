/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 18:22:06 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 20:10:36 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *convert_str(t_printf_arg *arg)
{
	char *new = ft_strdup(arg->arg.s);//
	return (new);
}