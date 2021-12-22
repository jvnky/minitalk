/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:43:39 by ychair            #+#    #+#             */
/*   Updated: 2021/12/20 12:43:39 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define	MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/src/ft_printf.h"

void	create_bin_str(int sig);
void	bin_to_dec(char *bin_str);

void	convert_n_send_msg(char *input, int pid);
void	dec_to_bin(int val, int pid);
void	send_msg(char *str, int pid);

#	endif