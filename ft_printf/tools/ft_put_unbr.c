/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:45:51 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:45:55 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_put_unbr(unsigned int n, int *len)
{
	long	b;

	b = n;
	if (b > 9)
	{
		ft_put_unbr(b / 10, *&len);
		ft_put_unbr(b % 10, *&len);
	}
	else
		*len += ft_putchar (b + '0');
}
