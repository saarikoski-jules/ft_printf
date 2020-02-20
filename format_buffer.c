/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_buffer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 20:37:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 19:18:35 by jsaariko      ########   odam.nl         */
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
	if (arg->precision == 0 && arg->arg.i == 0)
	{
		// printf("\n\ni should zero out\n");
		prec = 0;
		len = 0;
	}
	new = (char *)ft_calloc(prec + 1, sizeof(char));//
	if (!new)
		return (NULL);
	ft_memset(new, '0', prec);
	ft_memcpy(new + (prec - len), str, len);
	// printf("new: '%s'\n\n", new);
	return (new);
}

char *fill_buffer(t_printf_arg *arg, char *conv_str)
{
	char	*new;
	size_t	len;
	char 	c;

	new = NULL;
	len = ft_strlen(conv_str);
	printf("len %d\n", len);
	// printf("padding type %d\n", arg->pad_type);
	// printf("precision %d\n", arg->precision);
	// printf("field width %d\n", arg->field_width);
	c = (arg->pad_type == p_zero) ? '0' : ' ';//
	printf("c '%c'\n", c);

	// printf("padding with '%c'\n", c);
	arg->field_width = (arg->field_width > len) ? arg->field_width : len;//
	printf("field width: %d\n", arg->field_width);
	// printf("field width: %d\n", arg->field_width);
	new = (char *)ft_calloc(arg->field_width + 1, sizeof(char));//
	if (!new)
		return (NULL);
	printf("new before memset: '%s'\n", new + 2);
	ft_memset(new, c, arg->field_width);
	printf("new: '%s'\n", new);
	return (new);
}
