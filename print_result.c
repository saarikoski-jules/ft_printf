/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:05:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 12:38:56 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_item(const char *str, int len)
{
	// printf("\n\nIN PRINT ITEM\n\nstr: '%s'\nlast char: '%c'\nlen: %d\n\nFINISH PRINT ITEM\n\n", str, str[len], len);

	write(1, str, len);

	// write(1, "\n\n\n", 3);

	return(1);
}

int manage_print(const char *str, t_printf_arg **head)
{
	t_printf_arg	*cur_arg;
	char			*arg_str;
	char			*item;
	int				len;
	int				i;
	// char			*convs = "cspdiuxX%";//


	i = 0;
	len = 0;
	cur_arg = *head;
	while (1)
	{
		if (str[i] == '%' || str[i] == '\0')
		{
			print_item(str + len, i - len);
			// if (str[i] != '\0')
				// i += 3;
			// i = i + ft_strchrset(str + 1, convs);
			// printf("\ni = %d\nnext char = '%s'\n", i, str + i + ft_strchrset(str + i, convs) + 1);
			// printf("\ni = %d\n", i);
			len = i + 2 + ft_strchrset(str + i + 1, "cspdiuxX%"); //plus the conversion etc
			// printf("\nstr[i + 1] == '%c'\n", str[i + 1]);
			if (str[i] == '%')
			{			
				arg_str = execute_arg(cur_arg);//
				// printf("ARG: %s\n", arg_str);
				cur_arg = cur_arg->next;
				print_item(arg_str, ft_strlen(arg_str));
				free(arg_str);
			}
			if (str[i] == '\0')
				return (1);
		}
		// printf("\nstill going? str[i] == %c\n", str[i]);
		// printf_item(item, len);
		i++;
	}
	// while (cur_arg != NULL)
	// {
	// 	arg_str = execute_arg(cur_arg);//
	// 	// printf("ARG: %s\n", arg_str);
	// 	cur_arg = cur_arg->next;
	// 	free(arg_str);
	// }
	// printf("\n");
	// (void)str;
	return (1);
}