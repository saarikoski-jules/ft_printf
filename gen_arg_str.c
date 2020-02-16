/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_arg_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 15:27:26 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 19:02:55 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_fw(t_printf_arg *arg, char *conv_str)
{
	char *new = NULL;
	size_t	len;
	char 	c;
	size_t	field_width;

	len = ft_strlen(conv_str);
	c = (arg->pad_type == p_zero) ? '0' : ' ';//
	field_width = (arg->field_width > len) ? arg->field_width : len;//
	new = (char *)ft_calloc(field_width + 1, sizeof(char));

	ft_memset(new, c, field_width);
	// printf("padding: '%c'\n", c);
	// printf("fw: '%zu'\n", field_width);
	// printf("new: '%s'\n", new);
	return (new);
}

void cpy_from(char **final, char *conv, int index)
{
	int i;

	i = 0;
	// printf("string first: '%s'\n", *final);
	while (conv[i] != '\0')
	{
		if (conv[i] != '\0')
			(*final)[index + i] = conv[i];
		i++;
	}
	// printf("string here: '%s'\n", *final);
}

void add_conv(char **final, char *conv, t_printf_arg *arg)
{
	int i;

	i = 0;
	if (arg->pad_type == p_left)
		cpy_from(final, conv, 0);
	else
		cpy_from(final, conv, arg->field_width - ft_strlen(conv));
	if (arg->conv == p)
	{
		if (arg->pad_type == p_normal)
			cpy_from(final, "0x", arg->field_width - ft_strlen(conv));
		else
			cpy_from(final, "0x", 0);
	}
}