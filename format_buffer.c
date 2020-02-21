/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_buffer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 20:37:40 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/21 23:51:52 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


//prooblem

//stupid i hate

//youre trash

// char *apply_precision(t_printf_arg *arg, char *str)
// {
// 	size_t prec;
// 	size_t i;
// 	char *new;
// 	size_t len;

// 	i = 0;
// 	if (arg->precision == 0 && arg->arg.i == 0)
// 	{
// 		// printf("\n\ni should zero out\n");
// 		prec = 0;
// 		// len = 0;
// 	}
// 	else
// 		prec = (ft_numlen(arg->arg.i) > arg->precision) ? ft_numlen(arg->arg.i) : arg->precision;
// 	len = ft_strlen(str);
// 	// if (arg->precision < len)
// 		// prec = len;
// 	// else
// 		// prec = arg->precision;
// 	// printf("\nAPPLY_PRECISION:\nSTR: %s\nPRECISION: %d\nPREC: %d\nLEN: %d\n", str, arg->precision, prec, len);
// 	new = (char *)ft_calloc(prec + 1, sizeof(char));//
// 	if (!new)
// 		return (NULL);
// 	ft_memset(new, '0', prec);
// 	ft_memcpy(new + (prec - len), str, len);

// 	//PLEASE DOUBLE CHECK THE MATH HERE WITH PRECSION AND LENGTH

// 	// printf("new: '%s'\n\n", new);
// 	return (new);
// }

//get actual precision:
//min numlen, if precision more than numlen, numlen. This way I'll only need stringlen for pointers.
//if strlen is 2 more than numlen, its a pointer

// char *apply_precision(t_printf_arg *arg, char *str)
// {
// 	// printf("\nSTR IN APPLY PRECISION'%s'\n", str);
// 	char *new;
// 	int prec;
// 	int len;

// 	prec = ft_numlen(arg->precision);
// 	len = ft_strlen(str);
// 	if (arg->precision == 0 && arg->arg.i == 0)
// 	{
// 		prec = 0;
// 	}
// 	printf("\n\nlen = %d\nprec: %d\nstr: %s\n\n", len, prec, str);
// 	new = ft_strdup(str);
// 	(void)arg;
// 	return (new);
// }

//rerite apply_precision

//apply precision:
//fill buffer with as many zeroes as thee actual precision is
//run apply precision before memcpying the actual numstr over

char *apply_precision(t_printf_arg *arg)
{
	int prec;
	char *new;
	int base;

	if (arg->conv == p || arg->conv == x || arg->conv == X)
		base = 16;
	else
		base = 10; //get accurate base
	// printf("\n\nbase: %d\n\n", base);
	if (arg->arg.i == 0 && arg->precision == 0)
		prec = 0;
	else
		prec = (ft_numlen_base(arg->arg.i, base) > arg->precision) ? ft_numlen_base(arg->arg.i, base) : arg->precision;
	// printf("\n\nnumlen: %d\nnum: %llx\n\n", ft_numlen_base(arg->arg.i, 16), arg->arg.i);

	//check which value gets passed into numlen base


	//Use base instead so you can also work with hex
	// printf("\n\nPREC: %d\n\n", prec);//
	new = (char *)ft_calloc(prec + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memset(new, '0', prec);
	return (new);
}

char *fill_buffer(t_printf_arg *arg, char *conv_str)
{
	char	*new;
	size_t	len;
	char 	c;

	new = NULL;
	len = ft_strlen(conv_str);
	// printf("\n\nlen %d, conv_str: '%s'\n\n", len, conv_str);
	// printf("padding type %d\n", arg->pad_type);
	// printf("precision %d\n", arg->precision);
	// printf("field width %d\n", arg->field_width);
	c = (arg->pad_type == p_zero) ? '0' : ' ';//
	// printf("c '%c'\n", c);

	// printf("padding with '%c'\n", c);
	arg->field_width = (arg->field_width > len) ? arg->field_width : len;//
	// printf("field width: %d\n", arg->field_width);
	// printf("field width: %d\n", arg->field_width);
	new = (char *)ft_calloc(arg->field_width + 1, sizeof(char));//
	if (!new)
		return (NULL);
	// printf("new before memset: '%s'\n", new + 2);
	ft_memset(new, c, arg->field_width);
	// printf("new: '%s'\n", new + 2);
	return (new);
}
