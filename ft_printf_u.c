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

/* Prints an unsigned integer to terminal, return string length */

#include <unistd.h>
#include "libftprintf.h"

#define DEC_BASE (10)
#define DEC_MAX_LEN (12)

int	ft_printf_u(unsigned int n)
{
	int			i;
	int			len;
	char		s[DEC_MAX_LEN];
	char const	*dec_chars = "0123456789";

	i = DEC_MAX_LEN - 1;
	s[i--] = '\0';
	while (n >= DEC_BASE)
	{
		s[i] = dec_chars[n % DEC_BASE];
		n /= DEC_BASE;
		i--;
	}
	s[i] = dec_chars[n];
	len = DEC_MAX_LEN - 1 - i;
	write(STDOUT_FILENO, s, len);
	return (len);
}
