/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:42:27 by ychair            #+#    #+#             */
/*   Updated: 2021/12/23 17:44:10 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	tricksleep(pid_t pid)
{
	kill(pid, SIGUSR1);
	usleep(90);
}

void	delivery(pid_t pid, char *message)
{
	int	i;
	int	pos;
	int	bit[8];

	i = -1;
	while (message[++i])
	{
		pos = -1;
		while (++pos < 8)
		{
			bit[7 - pos] = message[i] % 2;
			message[i] /= 2;
		}
		pos = 0;
		while (pos < 8)
		{
			if (bit[pos++] == 1)
				tricksleep(pid);
			else
				kill(pid, SIGUSR2);
			usleep(90);
		}
	}
}

int	main(void)
{
	int	i;
	int	num;

	g_data.count = 0;
	i = 0;
	num = 1;
	while (i < 8)
	{
		g_data.pow_2[i] = num;
		num = num * 2;
		i++;
	}
	ft_putstr("Server pID: ");
	ft_putnbr(getpid());
	ft_putstr("\nWaiting for a message...\n");
	while (42)
	{
		signal(SIGUSR1, processing);
		signal(SIGUSR2, processing);
		pause();
	}
	return (0);
}
