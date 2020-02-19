/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:05:00 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:01:06 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_arg	*gen_elem(t_printf_arg **head)
{
	t_printf_arg	*cur;
	t_printf_arg	*new;

	new = malloc(sizeof(t_printf_arg));//
	if (!new)
		return (NULL);
	new->next = NULL;
	new->pad_type = p_normal;
	new->field_width = 0;
	new->precision = 0;
	if (*head == NULL)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	return(new);
}

int store_conv(char c, t_printf_arg **cur, va_list ap)
{
	if (ft_strchr("uxX", c))
		store_uint(c, cur, ap);
	if (ft_strchr("cdi%", c))
		store_int(c, cur, ap);
	if (ft_strchr("sp", c))
	{
		if (store_other(c, cur, ap) == -1)
			return (-1);
	}
	return (1);
}

int	gen_arg_list(t_printf_arg **head, const char *str, va_list ap)
{
	int				i;
	t_printf_arg	*cur;
	char			*format_str;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			cur = gen_elem(head);
			format_str = ft_strdupchr(str + i + 1, "cspdiuxX%");//
			if (!format_str)
				return (-1);
			manage_parser(&cur, format_str);
			free(format_str);
			i += ft_strchrset(str + i + 1, "cspdiuxX%");
			if (store_conv(str[i + 1], &cur, ap) == -1)//
				return (-1);
			i++;
		}
		i++;
	}
	return (1);
}