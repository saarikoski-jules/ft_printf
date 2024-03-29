/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupperstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 13:45:10 by jsaariko       #+#    #+#                */
/*   Updated: 2020/02/16 15:45:28 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_toupperstr(char **str)
{
	int i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		(*str)[i] = ft_toupper((*str)[i]);
		i++;
	}
}
