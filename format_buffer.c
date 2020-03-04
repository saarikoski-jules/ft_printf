/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_buffer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 14:52:06 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/04 14:58:52 by jsaariko      ########   odam.nl         */
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

char *apply_precision(t_printf_arg **arg)
{
	int prec;
	char *new;
	int base;

	// printf("uint is: %d", arg->arg.u);
	if ((*arg)->conv == p || (*arg)->conv == x || (*arg)->conv == X)
		base = 16;
	else
		base = 10; //get accurate base
	// printf("\n\nbase: %d\n\n", base);
	if ((*arg)->arg.i == 0 && (*arg)->precision == 0)
		prec = 0;
	else if ((*arg)->arg.i == 0 && (*arg)->precision == -1)
		prec = 1;
	else
// <<<<<<< HEAD
		prec = (ft_numlen_base((*arg)->arg.i, base) > (*arg)->precision) ? ft_numlen_base((*arg)->arg.i, base) : (*arg)->precision;
	if ((*arg)->arg.i < 0)
		prec++;
	// printf("uint is: %ld", arg->arg.i);
	// printf("uint is: %llx", (long long)arg->arg.i);

	// printf("\n\nnumlen: %d\nnum: %llx\n\n", ft_numlen_base(arg->arg.i, base), arg->arg.i);
	// printf("\n\nnumlen: %d\nnum: %llx\n\n", ft_numlen_base(arg->arg.u, base), arg->arg.u);
// =======
// 	{
// 		// prec = (ft_numlen_base((*arg)->arg.i, base) > (*arg)->precision) ? ft_numlen_base((*arg)->arg.i, base) : (*arg)->precision;

// 		if (ft_numlen_base((*arg)->arg.i, base) > (*arg)->precision)
// 		{
// 			prec = ft_numlen_base((*arg)->arg.i, base);
// 		}
// 		else
// 		{
// 			// printf("\nBROKE??\n");
// 			prec = (*arg)->precision;
// 			if (((*arg)->conv == i || (*arg)->conv == d) && (*arg)->arg.i < 0)
// 				prec++;
// 		}
// 	}

// //Add extra zero when:
// // precision is defined and is more or equal to

// // prec is more than numlen and precision is defined
// 	// printf("\n\nnumlen: %d\nprec: %d\nprecision: %d\n\n", ft_numlen((*arg)->arg.i), prec, (*arg)->precision);

// 	// if ((*arg)->arg.i < 0 && prec <= (ft_numlen((*arg)->arg.i)) && (*arg)->precision != -1)
// 		// printf("\nhere?\n");
// 		// prec++;
// 	// if (((*arg)->conv == i || (*arg)->conv == d) && (*arg)->arg.i < 0 && (*arg)->precision != -1)
// 		// prec++;
		
// 	// if ((*arg)->arg.i < 0 && (*arg)->precision != ft_numlen_base((*arg)->arg.i, base))
// 		// prec--;
// 	// printf("uint is: %ld", (*arg)->arg.i);
// 	// printf("uint is: %llx", (long long)(*arg)->arg.i);

// 	// printf("\n\nnumlen: %d\nnum: %llx\n\n", ft_numlen_base((*arg)->arg.i, base), (*arg)->arg.i);
// 	// printf("\n\nnumlen: %d\nnum: %llx\n\n", ft_numlen_base((*arg)->arg.u, base), (*arg)->arg.u);
// >>>>>>> 370c220597dd39c77e26158b4666d8af8c76b084

	//check which value gets passed into numlen base

	(*arg)->arg_width = prec;
	//Use base instead so you can also work with hex
	// printf("\n\nPREC: %d\n\n", prec);//
	// printf("\n\nprec: %d, precision: %d, numlen arg: %d\n\n", prec, (*arg)->precision, ft_numlen_base((*arg)->arg.i, base));
	new = (char *)ft_calloc(prec + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memset(new, '0', prec);
	// printf("\n\nnew: %s\n\n", new);
	return (new);
}

char *fill_buffer(t_printf_arg **arg, char *conv_str)
{
	char	*new;
	size_t	len;
	char 	padding;

	// printf("'%s'", conv_str);
	new = NULL;
	len = (*arg)->arg_width;
	// printf("\n\nlen %d, conv_str: '%s'\n\n", len, conv_str);
	// printf("padding type %d\n", (*arg)->pad_type);
	// printf("precision %d\n", arg->precision);
	// printf("field width %d\n", arg->field_width);
	padding = ((*arg)->pad_type == p_zero) ? '0' : ' ';//
	// printf("\n\npad type before: '%c'\n\n", padding);

	if (((*arg)->conv != s && (*arg)->conv != c) && (*arg)->precision != -1)
		padding = ' ';
	// printf("\n\npad type: '%c'\n\n", padding);

	// printf("padding with '%c'\n", c);
	(*arg)->field_width = ((*arg)->field_width > len) ? (*arg)->field_width : len;//
	// printf("field width: %d\n", (*arg)->field_width);
	// printf("field width: %d\n", (*arg)->field_width);
	new = (char *)ft_calloc((*arg)->field_width + 1, sizeof(char));//
	if (!new)
		return (NULL);
	// printf("new before memset: '%s'\n", new + 2);
	// printf("\n\nwidth: '%d', char '%c', new: '%s'\n", (*arg)->field_width, padding, new);
	ft_memset(new, padding, (*arg)->field_width);
	// printf("\n\n'%s'\n\n", new);
	// printf("new: '%s'\n", new + 2);
	return (new);
}

//TODO Rework so that I can pass argument length into the write function in case of zero chars