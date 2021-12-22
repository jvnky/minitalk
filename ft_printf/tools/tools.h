/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychair <ychair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:34:11 by ychair            #+#    #+#             */
/*   Updated: 2021/11/08 12:41:53 by ychair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct t_print
{
	va_list		args;

}t_print;

int			ft_putchar(char c);
void		ft_putnbr(int n, int *len);
int			ft_putstr(char *s);
int			check_type(t_print *param, const char *str, int *i);
void		format_c(t_print *param, int *len);
void		format_nbr(t_print *param, int *len);
void		format_str(t_print *param, int *len);
void		format_u(t_print *param, int *len);
void		ft_put_unbr(unsigned int n, int *len);
void		ft_convert(unsigned int n, char type, int *len);
void		format_x(t_print *param, char str, int *len);
void		format_p(t_print *param, int *len);
void		convertp(unsigned long n, int *len);

#endif
