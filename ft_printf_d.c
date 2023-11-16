/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:15:25 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 18:36:30 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints a integer to terminal, return string length */

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include "libftprintf.h"
#include "libft/libft.h"

#define DEC_BASE (10)
#define DEC_MAX_LEN (16)

int	ft_printf_d(int n)
{
	int			i;
	int			len;
	bool		is_negative;
	char		s[DEC_MAX_LEN];
	char const	*dec_chars = "0123456789";

	is_negative = false;
	if (n < 0)
		is_negative = true;
	i = 0;
	while (n / DEC_BASE)
	{
		s[i] = dec_chars[ft_abs(n % DEC_BASE)];
		n = ft_abs(n / DEC_BASE);
		i++;
	}
	s[i++] = dec_chars[n];
	if (is_negative)
		s[i++] = '-';
	s[i] = '\0';
	str_rev(s);
	len = (int)ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}
