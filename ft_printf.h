/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:17:08 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/17 17:38:00 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_printf_all(va_list args, int str_i);

int		ft_printf_c(char c);

int		ft_printf_s(char *s);

int		ft_printf_p(void *ptr);

int		ft_printf_d(int num);

int		ft_printf_u(unsigned int n);

int		ft_printf_x(int n, int x);

int		ft_abs(int n);

#endif
