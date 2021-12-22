/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:42:27 by ychair            #+#    #+#             */
/*   Updated: 2021/12/22 05:42:27 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

pid_t	pid_parser(char *str)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + str[i] - 48;
			if (num > 500000000)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (num);
}

void	delivery(pid_t pID, char *message)
{
	int	i;
	int	pos;
	int	bit[8];

	i = 0;
	while (message[i])
	{
		pos = 0;
		while (pos < 8)
		{
			bit[7 - pos] = message[i] % 2;
			message[i] /= 2;
			pos++;
		}
		pos = 0;
		while (pos < 8)
		{
			if (bit[pos++] == 1)
				kill(pID, SIGUSR1);
			else
				kill(pID, SIGUSR2);
			usleep(60);
		}
		i++;
	}
}

int	main(int args, char **argv)
{
	pid_t	pID;

	if (args != 3)
	{
		ft_putstr("Error\nInvalid number of arguments\n");
		return (1);
	}
	pID = pid_parser(argv[1]);
	if (pID == 0)
	{
		ft_putstr("Error\npID bad number\n");
		return (1);
	}
	ft_putstr(argv[1]);
	delivery(pID, argv[2]);
	ft_putstr("\nSending is completed\n");
	return (0);
}