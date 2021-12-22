/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:46:40 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:47:31 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_convert(unsigned int n, char type, int *len)
{
	char	*base;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		ft_convert(n / 16, type, *&len);
		ft_convert(n % 16, type, *&len);
	}
	else
		*len += ft_putchar(base[n]);
}

void	format_x(t_print *param, char str, int *len)
{
	unsigned int	number;

	number = va_arg(param->args, unsigned int);
	ft_convert(number, str, *&len);
}
