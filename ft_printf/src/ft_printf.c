/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:22:13 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:41:57 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	t_print		*param;

	param = (t_print *)malloc(1 * sizeof(t_print));
	if (!param)
		return (0);
	i = 0;
	len = 0;
	va_start(param->args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len = len + check_type(param, str, &i);
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	free(param);
	va_end(param->args);
	return (len);
}
