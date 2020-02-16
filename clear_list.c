/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 13:13:27 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:05:27 by jsaariko      ########   odam.nl         */
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
		// printf("%d, %d\n", tmp->conv, cur->conv);
		tmp = tmp->next;
		if (cur->conv == s)
			free(cur->arg.s);
		free(cur);
		cur = NULL;
	}
	// printf("head: %p, %p\n", head, *head);
	*head = NULL;
	// printf("head: %p, %p\n", head, *head);

	// free(*head);
	// t_printf_arg *tmp;

	// tmp = *head;

	// while (tmp->next != NULL)
	// {
	// 	printf("arg is %d\n", tmp->conv);

	// 	tmp = tmp->next;
	// }
}