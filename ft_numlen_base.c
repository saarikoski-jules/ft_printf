/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:00:21 by jsaariko       #+#    #+#                */
/*   Updated: 2019/12/05 21:43:09 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>//REMOVE
int	ft_numlen_base(int n, int base)
{
	int l;
	long num;

	num = (long)n;
	l = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		l++;
	while (num != 0)
	{
		num /= base;
		l++;
	}
	return (l);
}