/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:04:08 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/19 14:19:56 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void store_uint(char c, t_printf_arg **cur, va_list ap)
{
	if (c == 'u')
	{
		(*cur)->arg.u = va_arg(ap, unsigned int);
		(*cur)->conv = u;
	}
	else if (c == 'X')
	{
		(*cur)->arg.X = va_arg(ap, unsigned int);
		(*cur)->conv = X;
	}
	else if (c == 'x')
	{
		(*cur)->arg.x = va_arg(ap, unsigned int);
		(*cur)->conv = x;
	}
}

void store_int(char c, t_printf_arg **cur, va_list ap)
{
	if (c == 'd')
	{
		(*cur)->arg.d = va_arg(ap, int);
		(*cur)->conv = d;
	}
	else if (c == 'i')
	{
		(*cur)->arg.i = va_arg(ap, int);
		(*cur)->conv = i;
	}
	else
	{
		(*cur)->conv = c;
		if (c == '%')
			(*cur)->arg.c = '%';
		else
			(*cur)->arg.c = (char)va_arg(ap, int);
	}
}

int store_other(char c, t_printf_arg **cur, va_list ap)
{
	if (c == 's')
	{
		(*cur)->arg.s = ft_strdup(va_arg(ap, char *));//
		if (!(*cur)->arg.s)
			return (-1);
		(*cur)->conv = s;
	}
	else if (c == 'p')
	{
		(*cur)->arg.p = va_arg(ap, void *);
		(*cur)->conv = p;
	}
	return (1);
}