/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:17:08 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/15 19:39:54 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_printf_c(char c);

int		ft_printf_s(char *s);

int		ft_printf_p(void *ptr);

int		ft_printf_d(int num);

void	str_rev(char *s);
