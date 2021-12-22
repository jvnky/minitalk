/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:43:44 by ychair            #+#    #+#             */
/*   Updated: 2021/12/20 12:43:44 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_dec(char *bin_str)
{
	int		dec_val;
	char	c;
	int		bin_val;

	bin_val = 128;
	dec_val = 0;
	while (*bin_str)
	{
		if (*bin_str == '1')
			dec_val += bin_val;
		bin_val /= 2;
		bin_str++;
	}
	c = dec_val;
	write(1, &c, 1);
	return ;
}

void	create_bin_str(int sig)
{
	static char	bin_str[9];
	static int	i;

	if (sig == SIGUSR1)
		bin_str[i++] = '0';
	else if (sig == SIGUSR2)
		bin_str[i++] = '1';
	if (i == 8)
	{
		bin_to_dec(bin_str);
		i = 0;
		*bin_str = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, &create_bin_str);
	signal(SIGUSR2, &create_bin_str);
	while (1)
		pause();
	return (0);
}