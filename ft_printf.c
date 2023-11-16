/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:56 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 19:12:55 by juli             ###   ########.fr       */
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
	size_t	i;
	size_t	sum;
	va_list	args;

	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
			sum += ft_printf_c(str[i++]);
		else
		{
			i++;
			// sum += ft_printf_all(args, str[i]);
			// replace this block with one function
			if (str[i] == 'c')
				sum += ft_printf_c(va_arg(args, int));
			else if (str[i] == 's')
				sum += ft_printf_s(va_arg(args, char *));
			else if (str[i] == 'p')
				sum += ft_printf_p(va_arg(args, void *));
			else if (str[i] == 'd' || str[i] == 'i')
				sum += ft_printf_d(va_arg(args, int));
			else if (str[i] == 'u')
				sum += ft_printf_u(va_arg(args, unsigned int));
			else if (str[i] == 'x' || str[i] == 'X')
				sum += ft_printf_x(va_arg(args, int), str[i]);
			else if (str[i] == '%')
				sum += ft_printf_c('%');
			else
				return (-1);
			i++;
		}
	}
	va_end(args);
	return (sum);
}
