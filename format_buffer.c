/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_buffer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 20:37:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 15:11:24 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_precision(t_printf_arg *arg, char *str)
{
	size_t prec;
	size_t i;
	char *new;
	size_t len;

	i = 0;
	len = ft_strlen(str);
	if (arg->precision < len)
		prec = len;
	else
		prec = arg->precision;
	new = (char *)ft_calloc(prec + 1, sizeof(char));//
	if (!new)
		return (NULL);
	ft_memset(new, '0', prec);
	ft_memcpy(new + (prec - len), str, len);
	return (new);
}

char *fill_buffer(t_printf_arg *arg, char *conv_str)
{
	char	*new;
	size_t	len;
	char 	c;

	new = NULL;
	len = ft_strlen(conv_str);
	c = (arg->pad_type == p_zero) ? '0' : ' ';//
	arg->field_width = (arg->field_width > len) ? arg->field_width : len;//
	new = (char *)ft_calloc(arg->field_width + 1, sizeof(char));//
	if (!new)
		return (NULL);
	ft_memset(new, c, arg->field_width);
	return (new);
}
