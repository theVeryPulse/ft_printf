/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:56 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 21:56:18 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	• %c Prints a single character.
	• %s Prints a string (as defined by the common C convention).
	• %p The void * pointer argument has to be printed in hexadecimal format.
	• %d Prints a decimal (base 10) number.
	• %i Prints an integer in base 10.
	• %u Prints an unsigned decimal (base 10) number.
	• %x Prints a number in hexadecimal (base 16) lowercase format.
	• %X Prints a number in hexadecimal (base 16) uppercase format.
	• %% Prints a percent sign.
*/

#include "libft/libft.h"
#include "libftprintf.h"
#include <stddef.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
		{
			sum += ft_printf_c(str[i]);
		}
		else
		{
			sum += ft_printf_all(args, str[++i]);
		}
		i++;
	}
	va_end(args);
	return (sum);
}
