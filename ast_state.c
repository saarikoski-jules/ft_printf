/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:14:00 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/20 18:26:43 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ast_state(char token, t_printf_arg **arg, va_list ap)
{
	int ast;

	// tmp = ft_lltoa_base(va_arg(ap, int), 10);//
	// manage_parser(arg, tmp, ap);
	ast = va_arg(ap, int);
	// printf("\nwildcard value: %d\n", ast);
	if (ast < 0)
	{
		(*arg)->pad_type = p_left;
		ast *= -1;
	}
	(*arg)->field_width = ast;
	// (*arg)->field_width = va_arg(ap, int);
	
	// manage_parser(arg, tmp, ap, &entry_state);
	(void)token;
}

void prec_ast_state(char token, t_printf_arg **arg, va_list ap)
{

	int ast;

	// tmp = ft_lltoa_base(va_arg(ap, int), 10);//
	// manage_parser(arg, tmp, ap);
	ast = va_arg(ap, int);
	// printf("\nwildcard value: %d\n", ast);

	if (ast < 0)
	{
		(*arg)->pad_type = p_left;
		(*arg)->precision = 1;
	}
	else
		(*arg)->precision = ast;

	// if (ast < 0)
	// 	(*arg)->pad_type = p_left;
	// // else
	// (*arg)->precision = ast;
	// // (*arg)->field_width = va_arg(ap, int);

	
	// manage_parser(arg, tmp, ap, &prec_state);
	(void)token;
	
	// (*arg)->precision = va_arg(ap, unsigned long long);
	// (void)token;
}

//FUCKIGN CALL MANAGE_PARSER FROM THE ASTERISK STATE
// EXCEPT NO CAUSE PRINTF IS STUPID AF