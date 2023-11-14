/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:20:22 by juli              #+#    #+#             */
/*   Updated: 2023/11/14 19:21:33 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Prints the address of a pointer to terminal in hexadecimal.
 * Returns the length of the printed string.
 */

#include <unistd.h>
#include <stdint.h>

int	ft_print_p(void *addr)
{
	intptr_t	addr_int;
	int			i;
	char		hexstr[19];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (intptr_t)addr;
	i = 0;
	while (addr_int / 10)
	{
		hexstr[i++] = hexchars[addr_int / 16];
	}
	hexstr[i++] = hexchars[addr_int];
	hexstr[i++] = 'x';
	hexstr[i++] = '0';
	hexstr[i] = '\0';

	i = 0;
	write(STDOUT_FILENO, hexstr, 16);
}

void	str_rev(char *s)
{
	size_t	left;
	size_t	right;
	char	swap;

	left = 0;
	right = ft_strlen(s) - 1;
	while (left < right)
	{
		swap = s[left];
		
	}
}
