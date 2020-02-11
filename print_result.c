/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:05:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/11 17:33:55 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int manage_print(const char *str, t_printf_arg **head)
{
	t_printf_arg	*cur_arg;
	char			*arg_str;

	cur_arg = *head;
	while (cur_arg != NULL)
	{	
		arg_str = execute_arg(cur_arg);
		printf("PRINT ARG: %s\n", arg_str);
		cur_arg= cur_arg->next;
	}
	(void)str;
	return (1);
}