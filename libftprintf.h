/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:17:08 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/14 18:22:23 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	ft_printf_c(char c);

int	ft_printf_s(char *s);

int	ft_printf_p(void *ptr);
