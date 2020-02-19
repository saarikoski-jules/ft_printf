/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:04:08 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 22:04:58 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void store_uint(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.u = va_arg(ap, unsigned long long);
	if (chr == 'u')
		(*cur)->conv = u;
	else if (chr == 'X')
		(*cur)->conv = X;
	else if (chr == 'x')
		(*cur)->conv = x;
}

void store_int(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.i = va_arg(ap, long long);
	if (chr == 'd')
		(*cur)->conv = d;
	else if (chr == 'i')
		(*cur)->conv = i;
}

void store_char(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->conv = c;
	if (chr == '%')
		(*cur)->arg.c = '%';
	else
		(*cur)->arg.c = (char)va_arg(ap, int);

	// printf("%c, %d\n", (*cur)->arg.c, (*cur)->conv);
}

int store_other(char chr, t_printf_arg **cur, va_list ap)
{
	if (chr == 's')
	{
		(*cur)->arg.s = ft_strdup(va_arg(ap, char *));//
		if (!(*cur)->arg.s)
			return (-1);
		(*cur)->conv = s;
	}
	else if (chr == 'p')
	{
		(*cur)->arg.p = va_arg(ap, void *);
		(*cur)->conv = p;
	}
	return (1);
}