/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:43:39 by ychair            #+#    #+#             */
/*   Updated: 2021/12/23 19:38:01 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	int		pow_2[8];
	int		bit[8];
	int		count;
}				t_data;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
#endif