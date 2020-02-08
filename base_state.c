/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:56 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/08 22:26:53 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void entry_state(char token, t_printf_arg **arg)
{
	printf("enter\n");//
}

void exit_state(char token, t_printf_arg **arg)
{
	printf("exit\n");
}
