/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_conv.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:04:08 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/05 14:54:33 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void store_uint(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.u = va_arg(ap, unsigned int);
	if (chr == 'u')
		(*cur)->conv = u;
	else if (chr == 'X')
		(*cur)->conv = X;
	else if (chr == 'x')
		(*cur)->conv = x;
	// (*cur)->precision = 1;
}

void store_int(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->arg.i = va_arg(ap, int);
	// printf("\n\nIN STORE INT %lld\n", (*cur)->arg.i);
	if (chr == 'd')
		(*cur)->conv = d;
	else if (chr == 'i')
		(*cur)->conv = i;
	// (*cur)->precision = 1;
}

void store_char(char chr, t_printf_arg **cur, va_list ap)
{
	(*cur)->conv = c;
	if (chr == '%')
		(*cur)->arg.c = '%';
	else
		(*cur)->arg.c = va_arg(ap, int);

	// printf("'%d'\n", (*cur)->arg.c);
}

int store_other(char chr, t_printf_arg **cur, va_list ap)
{
	char *tmp;

	if (chr == 's')
	{
		tmp = va_arg(ap, char *);
		if (tmp != NULL)
		{
			(*cur)->arg.s = ft_strdup(tmp);//
			if (!(*cur)->arg.s)
				return (-1);
		}
		else
			(*cur)->arg.s = ft_strdup("(null)");
		// printf("\nThis is where we segfault?\n");
		(*cur)->conv = s;
	}
	else if (chr == 'p')
	{
		(*cur)->arg.p = va_arg(ap, unsigned long);
		(*cur)->conv = p;
	}
	return (1);
}

//precision for floats is automatically 6