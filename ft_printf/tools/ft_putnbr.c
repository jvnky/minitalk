/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:43:55 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:44:42 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putnbr(int n, int *len)
{
	long	b;

	b = n;
	if (b < 0)
	{
		*len += ft_putchar('-');
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr(b / 10, len);
		ft_putnbr(b % 10, len);
	}
	else
		*len += ft_putchar(b + '0');
}
