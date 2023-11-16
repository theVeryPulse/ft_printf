/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:17:08 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/16 18:44:31 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_printf_c(char c);

int		ft_printf_s(char *s);

int		ft_printf_p(void *ptr);

int		ft_printf_d(int num);

int		ft_printf_u(unsigned int n);

int		ft_printf_x(int n, int x);

void	str_rev(char *s);

int		ft_abs(int n);

#endif
