/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_arg_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:05:00 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 14:18:10 by jsaariko      ########   odam.nl         */
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
	new->precision = -1;
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

int store_conv(char chr, t_printf_arg **cur, va_list ap)
{
	// printf("aaahhhhhhha");
	if (ft_strchr("uxX", chr))
		store_uint(chr, cur, ap);
	else if (ft_strchr("di", chr))
		store_int(chr, cur, ap);
	else if (ft_strchr("c%", chr))
		store_char(chr, cur, ap);
	else if (ft_strchr("sp", chr))
	{
		if (store_other(chr, cur, ap) == -1)
			return (-1);
	}
	return (1);
}

// int find_conv_str(const char *str)
// {
// 	int i;

// 	i = 0;
// 	while (ft_strchr("0123456789-*.", str[i]) != NULL)
// 		i++;
// 	return (i);
// }

int	gen_arg_list(t_printf_arg **head, const char *str, va_list ap)
{
	int				i;
	t_printf_arg	*cur;
	char			*format_str;
	int	len;
	int	ret;

	i = 0;
	ret = 1;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len = ft_strmatch(str + i, "0123456789-*.");
			format_str = (char *)ft_calloc(len + 1, sizeof(char));
			if (!format_str)
				return (-1);
			ft_strlcpy(format_str, str + i, len + 1);
			i += len;

			// printf("%c, %s\n", str[i], ft_strchr("cspdiuxX%", str[i]));

			if (ft_strchr("cspdiuxX%", str[i]) != NULL)
			{
				// printf("aa");
				cur = gen_elem(head);
				manage_parser(&cur, format_str, ap);
				if (store_conv(str[i], &cur, ap) == -1)//
				{
					free(format_str);
					return (-1);
				}
				// printf("\nret: %d\n", ret);
				// if (ret == 0)
			}
			// printf("\nstr: '%s'\n", format_str);
			// format_str = ft_strdupchr(str + i, "cspdiuxX%");//
			free(format_str);
			// i += ft_strchrset(str + i, "cspdiuxX%");
			// printf("char: str[%d] = '%s'\n", i, str + i);

			// printf("\n\nWORKS HERE: store_conv(str[%d + 1] = %c\n%s)\n\n", i, str[i + 1], str);
		}
		i++;
	}
	return (ret);
}

//should this return -1 when given a bad conversion


// TODO Change skipping of format string to instead of looking for conversion, it skips all formatting chars? If bad conversion, skip over conversion  0-*123456789.

//.-0123456789*