/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:05:56 by juli              #+#    #+#             */
/*   Updated: 2023/11/17 17:30:02 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints integer as hexadecimal to terminal.
 * Does not print a '-' when input is negative.
 * Returns the length of the printed string.
 * 
 * Parameters
 *     i: the number to print as decimal
 *     x: 'x' for lowercase and 'X' for uppercase
 */

#include <unistd.h>
#include "libftprintf.h"

#define HEXA_MAX_LEN (9)
#define HEXA_BASE (16)

static void	str_upper(char *s);

int	ft_printf_x(unsigned int n, int letter_case)
{
	int			i;
	char		s[HEXA_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	i = HEXA_MAX_LEN - 1;
	s[i--] = '\0';
	while (n >= HEXA_BASE)
	{
		s[i] = hexchars[ft_abs(n % HEXA_BASE)];
		n = ft_abs(n / HEXA_BASE);
		i--;
	}
	s[i] = hexchars[ft_abs(n)];
	if (letter_case == 'X')
		str_upper(&s[i]);
	return (ft_printf_s(&s[i]));
}

/* Converts all lower case letters to upper case in a string */
static void	str_upper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}
