/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:20:22 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 19:05:56 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints the address of a pointer to terminal in hexadecimal.
 * Returns the length of the printed string.
 */

#include <unistd.h>
#include <stdint.h>
#include "libft/libft.h"
#include "libftprintf.h"
#define HEXA_BASE (16)
#define ADDR_MAX_LEN (20)

int	ft_printf_p(void *addr)
{
	int			i;
	intptr_t	addr_int;
	char		s[ADDR_MAX_LEN];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (intptr_t)addr;
	i = 0;
	while (addr_int / HEXA_BASE)
	{
		s[i++] = hexchars[addr_int % HEXA_BASE];
		addr_int /= HEXA_BASE;
	}
	s[i++] = hexchars[addr_int];
	s[i++] = 'x';
	s[i++] = '0';
	s[i] = '\0';
	str_rev(s);
	write(STDOUT_FILENO, s, ft_strlen(s));
	return (ft_strlen(s));
}
