/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:05:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 22:14:32 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_item(const char *str, int len)
{
	return (write(1, str, len));
}

int manage_print(const char *str, t_printf_arg **head)
{
	t_printf_arg	*cur_arg;
	char			*arg_str;
	// char			*item;
	int				len;
	int				i;
	int				ret;

	i = 0;
	len = 0;
	ret = 0;
	cur_arg = *head;
	while (1)
	{
		if (str[i] == '%' || str[i] == '\0')
		{
			ret += print_item(str + len, i - len);
			len = i + 2 + ft_strchrset(str + i + 1, "cspdiuxX%"); //plus the conversion etc
			if (str[i] == '%')
			{			
				// printf("str[i] = '%c, i = %d'\n", str[i], i);
				arg_str = execute_arg(cur_arg);//
				if (!arg_str)
				{
					return (-1);
				}
				cur_arg = cur_arg->next;
				ret += print_item(arg_str, ft_strlen(arg_str));
				if (ret == -1)
				{
					free(arg_str);
					return (-1);
				}
				free(arg_str);
			}
			if (str[i] == '\0')
				return (ret);
		}
		i++;
	}
	return (ret);
}