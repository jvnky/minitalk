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

int	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (*c != '\0')
	{
		count++;
		c++;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		return (0);
	if ((*str) == '-' || (*str) == '+')
	{
		if (*str == '+')
			sign = 1;
		else
			sign = -1;
		++str;
	}
	while ((*str >= 48) && (*str <= 57))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}

void	send_newline(int pid)
{
	char	a;
	int		n;

	a = '\n';
	n = 1;
	while (n <= 128)
	{
		if (a & n)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n *= 2;
		usleep(100);
	}
}

void	send_chars(int pid, char **argv)
{
	int	len;
	int	n;
	int	i;

	len = ft_strlen(argv[2]);
	i = 0;
	while (i < len)
	{
		n = 1;
		while (n <= 128)
		{
			if (argv[2][i] & n)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			n *= 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_chars(pid, argv);
	send_newline(pid);
}