/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:12:12 by juli              #+#    #+#             */
/*   Updated: 2023/11/17 17:29:43 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints a string to terminal, returns string length.
 */

/* LOG
 *
 * 17/11/2023
 * Bug fix: in case of NULL pointer, writes "(null)".
 */
#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

int	ft_printf_s(char *s)
{
	int	len;

	if (s == NULL)
	{
		len = 6;
		write(STDOUT_FILENO, "(null)", len);
	}
	else
	{
		len = (int)ft_strlen(s);
		write(STDOUT_FILENO, s, len);
	}
	return (len);
}
