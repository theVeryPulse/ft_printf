/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:40:17 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 19:06:16 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#define DEC_BASE (10)

int	ft_printf_u(unsigned int n)
{
	int			i;
	int			len;
	char		s[20];
	char const	*dec_chars = "0123456789";

	i = 0;
	while (n / DEC_BASE)
	{
		s[i] = dec_chars[n % DEC_BASE];
		n /= DEC_BASE;
		i++;
	}
	s[i++] = dec_chars[n];
	s[i] = '\0';
	str_rev(s);
	len = (int)ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}
