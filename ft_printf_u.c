/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:40:17 by juli              #+#    #+#             */
/*   Updated: 2023/11/17 17:29:49 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints an unsigned integer to terminal, return string length.
 */

#include <unistd.h>
#include "libftprintf.h"

#define DEC_BASE (10)
#define DEC_MAX_LEN (12)

int	ft_printf_u(unsigned int n)
{
	int			i;
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
	return (ft_printf_s(&s[i]));
}
