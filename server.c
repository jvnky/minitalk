/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:43:44 by ychair            #+#    #+#             */
/*   Updated: 2021/12/23 17:47:01 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == 0)
		return ;
	ft_putnbr(n / 10);
	ft_putchar(((n % 10) + 48));
}

void	processing(int signal)
{
	int	symbol;
	int	pos;

	g_data.bit[g_data.count] = signal;
	g_data.count++;
	if (g_data.count >= 8)
	{
		symbol = 0;
		pos = 0;
		while (pos < 8)
		{
			if (g_data.bit[7 - pos] == SIGUSR1)
				symbol += g_data.pow_2[pos];
			pos++;
		}
		ft_putchar(symbol);
		g_data.count = 0;
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
