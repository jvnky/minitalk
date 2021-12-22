/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 04:45:55 by ychair            #+#    #+#             */
/*   Updated: 2021/12/22 04:45:55 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <limits.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}


static int	ft_isWhitespace(char c)
{
	if (c == ' ' || (c >= '\b' && c <= '\r'))
		return (1);
	return (0);
}

static int	ft_calcRes(const char *str, int sign)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (ft_isdigit(*str) - '0');
		if (sign == -1 && res >= INT_MAX)
			return (INT_MIN);
		else if (res >= INT_MAX)
			return (INT_MAX);
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	if (!ft_strlen(str))
		return (0);
	res = 0;
	sign = 1;
	while (ft_isWhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = ft_calcRes(str, sign);
	return (res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	byte_size;

	byte_size = count * size;
	res = malloc(byte_size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, byte_size);
	return (res);
}


void	ft_bzero(void *s, size_t len)
{
	if (len)
		ft_memset(s, 0, len);
}