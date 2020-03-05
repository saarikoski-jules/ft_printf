/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 18:15:21 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 18:15:24 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	t_printf_arg	*head;
	va_list			ap;
	int				ret;

	head = NULL;
	va_start(ap, str);
	if (gen_arg_list(&head, str, ap) == -1)
	{
		clear_list(&head);
		return (-1);
	}
	va_end(ap);
	ret = manage_print(str, &head);
	clear_list(&head);
	return (ret);
}
