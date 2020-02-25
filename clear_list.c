/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 13:13:27 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/25 17:14:58 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//
void clear_list(t_printf_arg **head)
{
	t_printf_arg *tmp;
	t_printf_arg *cur;

	tmp = *head;
	cur = *head;
	while (tmp != NULL)
	{
		cur = tmp;
		tmp = tmp->next;
		if (cur->conv == s)
			free(cur->arg.s);
		free(cur);
		cur = NULL;
	}
	*head = NULL;
}