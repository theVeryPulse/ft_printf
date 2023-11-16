/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:09 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/15 19:50:10 by juli             ###   ########.fr       */
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
	
	WD
	└─ ft_printf_c.c
	└─ ft_printf_s.c
	└─ ft_printf_p.c
	└─ ft_printf_d.c
	└─ ft_printf_i.c
	└─ ft_printf_u.c
	└─ ft_printf_x.c
	└─ ft_printf_X.c
	└─ ft_printf_percentsign.c
	└─ libft/
*/

#include "libft/libft.h"
#include "libftprintf.h"
#include <stddef.h>
#include <stdarg.h> /* va_arg */

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
		else // cspdiuxX%
		{
			i++;
			if (str[i] == 'c')
				sum += ft_printf_c(va_arg(args, int));
			else if (str[i] == 's')
				sum += ft_printf_s(va_arg(args, char *));
			else if (str[i] == 'p')
				sum += ft_printf_p(va_arg(args, void *));
			else if (str[i] == 'd')
				sum += ft_printf_d(va_arg(args, int));
			/*
			else if (str[i] == 'i')
				;
			else if (str[i] == 'u')
				;
			else if (str[i] == 'x')
				;
			else if (str[i] == 'X')
				;
			*/
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
