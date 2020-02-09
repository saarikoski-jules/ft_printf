/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:01:38 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/09 23:13:04 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void num_state(char token, t_printf_arg **arg)
{
	// (!(*arg)->field_width)
	(*arg)->field_width = (token - 48);
	printf("current token: %c, arg: %zu\n", token, (*arg)->field_width);
	// else
	// {
	// 	(*arg)->field_width *= 10;
	// 	(*arg)->field_width += (token - 48);
	// }
}

void num_repeat_state(char token, t_printf_arg **arg)
{
	// printf("current num repeat: %c\n", token);
	(*arg)->field_width *= 10;
	(*arg)->field_width += (token - 48);
	printf("REPEAT current token: %c, arg: %zu\n", token, (*arg)->field_width);

}

void prec_num_state(char token, t_printf_arg **arg)
{
	(*arg)->precision = (token - 48);
	printf("precision current token: %c, arg: %zu\n", token, (*arg)->precision);
}

void prec_num_repeat_state(char token, t_printf_arg **arg)
{
	printf("precision REPEAT current token: %c, arg: %zu\n", token, (*arg)->precision);
	(*arg)->precision *= 10;
	(*arg)->precision += (token - 48);
	printf("precision REPEAT current token: %c, arg: %zu\n", token, (*arg)->precision);
}

// void num_dash_state(char token, t_printf_arg **arg)
// {
// 	printf("(dash) current num: %c\n", token);
// 	if (!(*arg)->field_width)
// 		(*arg)->field_width += (token - 48);
// 	else
// 	{
// 		(*arg)->field_width *= 10;
// 		(*arg)->field_width += (token - 48);
// 	}
// 	// printf("cur field width: %d\n", (*arg)->field_width);

// }
