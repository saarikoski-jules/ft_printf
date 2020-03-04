/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 12:05:50 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/04 18:12:59 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int print_item(const char *str, int len)
{

	// printf("\n\nitem: '%s', len %d\n\n", str, len);
	return (write(1, str, len));
}

// int manage_print(const char *str, t_printf_arg **head)
// {
// 	t_printf_arg	*cur_arg;
// 	char			*arg_str;
// 	// char			*item;
// 	int				len;
// 	int				i;
// 	int				ret;

// 	i = 0;
// 	len = 0;
// 	ret = 0;
// 	cur_arg = *head;
// 	while (1)
// 	{
// 		// printf("str[%d] == '%c'\n", i, str[i]);
// 		if (str[i] == '%' || str[i] == '\0')
// 		{
// 			ret += print_item(str + len, i - len);
// 			len = i + 2 + ft_strchrset(str + i + 1, "cspdiuxX%"); //plus the conversion etc
// 			// printf("%d\n", len);
// 			if (str[i] == '%')
// 			{			
// 				// printf("str[i] = '%c, i = %d'\n", str[i], i);
// 				arg_str = execute_arg(&cur_arg);//
// 				if (!arg_str)
// 				{
// 					return (-1);
// 				}
// 				ret += print_item(arg_str, cur_arg->field_width);
// 				if (cur_arg->next != NULL)
// 					cur_arg = cur_arg->next;
// 				if (ret == -1)
// 				{
// 					free(arg_str);
// 					return (-1);
// 				}
// 				free(arg_str);
// 			}
// 			if (str[i] == '\0')
// 				return (ret);
// 			if (i + 1 != '\0') //double check the necessity/logic here
// 				i++;
// 		}
// 		i++;
// 	}
// 	return (ret);
// }


// take out entire conversion from str

int print_conv(t_printf_arg **cur)
{
	char *arg_str;
	int ret;

// TODO Check if conversions valid and doesnt fail. If fails, ignore.

	arg_str = execute_arg(cur);
	ret = print_item(arg_str, (*cur)->field_width);
	return (ret);
}

int skip_conv(const char *str)
{
	int len;

	len = ft_strchrset(str + 1, "cspdiuxX%");
	// TODO change this into strncmp for 0123456789.-*
	// printf("\n\nformat str starts: %s\n\n", str);
	// printf("\n\nformat str length: %d\n\n", len);

	return (len + 2);
}

int manage_print(const char *str, t_printf_arg **head)
{
	t_printf_arg *cur_arg;
	int i;
	int prev;
	int ret;

	cur_arg = *head;
	i = 0;
	prev = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			// printf("\nprinting cur: '%s'\n", str + prev);
			ret += print_item(str + prev, i - prev);
			ret += print_conv(&cur_arg);
			// if (cur_arg->next != NULL)
			cur_arg = cur_arg->next;
			i += skip_conv(str + i);
			// printf("\n\nstr[%d] = %c\n\n", i, str[i]);
			prev = i;
			// printf("\nprev: %d\n", prev);
		}
		else
		{
			// printf("\nstr[%d] = '%c'\n", i, str[i]);
			i++;
		}
		//print everything up to a %
		//skip everything between % and conv
		// print_conv(&cur_arg);//print conversion
	}
	// printf("\n\nstart: '%s', len: %d\n\n", str + prev, i - prev);
	ret += print_item(str + prev, i - prev);
	// printf("\n\nFINISHED\n\n");
	return (ret);
}


// int write_string(const char *str, int *ret)
// {
// 	int len;

// 	len = 0;
// 	// printf("\n\nWRITE STRING: '%s', RET: %d\n\n", str, *ret);
// 	while(str[len] != '\0' && str[len] != '%')
// 	{
// 		// printf("str[%d] = %c\n", len, str[len]);
// 		len++;
// 	}
// 	*ret += print_item(str, len);
// 	// while (str[len] != '\0' || str[len] != '%')
// 	// {
// 	// 	printf("str[%d] = %c\n", len, str[len]);
// 	// 	len++;
// 	// }
// 	// *ret += print_item(str, len);
// 	printf("\n\nlen = %d\n\n", len);
// 	return (len);
// }

// int write_conv(t_printf_arg *arg, int *ret)
// {
// 	char *arg_str;
// 	int		len;

// 	arg_str = execute_arg(&arg);
// 	// printf("\n%s\n", arg_str);
// 	*ret = print_item(arg_str, arg->field_width);
// 	return (1);
// }

// int manage_print(const char *str, t_printf_arg **head)
// {
// 	t_printf_arg	*cur_arg;
// 	// char			*arg_str;
// 	int				ret;
// 	int				i;
// 	int				search;

// 	ret = 0;
// 	cur_arg = *head;
// 	i = 0;
// 	// printf("in manage print\n");
// 	while(str[i] != '\0')
// 	{
// 		// printf("\n\n\n--------STR[%d] = %c-------------\n\n\n", i, str[i]);
// 		i = i + write_string(str + i, &ret);
// 		// printf("\n\n-------- i = %d -------\n\n", i);
// 		if (cur_arg != NULL)
// 		{
// 			write_conv(cur_arg, &ret);
// 			cur_arg = cur_arg->next;
// 		}
// 		search = ft_strchrset(str + i + 1, "cspdiuxX%");
// 		// printf("string: %s\n", str + i + 1);
// 		if (search != -1)
// 			i = i + search + 1;
// 		// printf("'%c', %d, %d\n", str[i], i, search);
// 		// i++;

// 	}
// 	// while (str[i] != '\0')
// 	// {
// 		// printf("%d\n", i);
// 		// write_arg(cur_arg, &ret);
// 	// }
// 	return (ret);
// }