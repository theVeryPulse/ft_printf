/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:20:22 by juli              #+#    #+#             */
/*   Updated: 2023/11/15 19:30:31 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Prints the address of a pointer to terminal in hexadecimal.
 * Returns the length of the printed string.
 */

#include <unistd.h>
#include <stdint.h>
#include "libft/libft.h"
#define HEX_BASE (16)

static void	str_rev(char *s);

int	ft_printf_p(void *addr)
{
	intptr_t	addr_int;
	int			i;
	char		hexstr[19];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (intptr_t)addr;
	i = 0;
	while (addr_int / HEX_BASE)
	{
		hexstr[i++] = hexchars[addr_int % HEX_BASE];
		addr_int /= HEX_BASE;
	}
	hexstr[i++] = hexchars[addr_int];
	hexstr[i++] = 'x';
	hexstr[i++] = '0';
	hexstr[i] = '\0';
	str_rev(hexstr);
	write(STDOUT_FILENO, hexstr, ft_strlen(hexstr));
	return (ft_strlen(hexstr));
}

static void	str_rev(char *s)
{
	size_t	left;
	size_t	right;
	char	swap;

	left = 0;
	right = ft_strlen(s) - 1;
	while (left < right)
	{
		swap = s[left];
		s[left] = s[right];
		s[right] = swap;
		left++;
		right--;
	}
}
