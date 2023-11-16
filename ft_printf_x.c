/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:05:56 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 19:06:29 by juli             ###   ########.fr       */
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
#include "libft/libft.h"
#include "libftprintf.h"

#define HEXA_MAX_LEN (9)
#define HEXA_BASE (16)

static void	str_upper(char *s);

int	ft_printf_x(int n, int x)
{
	int			i;
	int			len;
	char		s[HEXA_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	i = 0;
	while (n / HEXA_BASE)
	{
		s[i] = hexchars[ft_abs(n % HEXA_BASE)];
		n = ft_abs(n / HEXA_BASE);
		i++;
	}
	s[i++] = hexchars[ft_abs(n)];
	s[i] = '\0';
	str_rev(s);
	if (x == 'X')
		str_upper(s);
	len = (int)ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}

/* Converts all lower case letters to upper case in a string */
static void	str_upper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}
