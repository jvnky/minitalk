/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:39:25 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:40:00 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdarg.h>

void	format_nbr(t_print *param, int *len)
{
	ft_putnbr(va_arg(param->args, int), *&len);
}
