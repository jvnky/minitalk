/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:40:12 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:41:34 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	convertp(unsigned long n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		convertp(n / 16, *&len);
		convertp(n % 16, *&len);
	}
	else
		*len += ft_putchar(base[n]);
}

void	format_p(t_print *param, int *len)
{
	unsigned long	n;

	n = va_arg(param->args, unsigned long);
	if (n == 0)
		*len += ft_putstr("0x0");
	else
	{
		*len += ft_putstr("0x");
		convertp(n, *&len);
	}
}
