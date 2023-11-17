/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:25:19 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 21:47:09 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Interprets the specifier passed into ft_printf.
 * Calls the corresponding function to print the argument.
 * Returns the length of the printed string.
 * Returns -1 if the specifier is not valid.
*/

#include "libftprintf.h"
#include <stdarg.h>

int	ft_printf_all(va_list args, int str_i)
{
	int	sum;

	sum = 0;
	if (str_i == 'c')
		sum += ft_printf_c(va_arg(args, int));
	else if (str_i == 's')
		sum += ft_printf_s(va_arg(args, char *));
	else if (str_i == 'p')
		sum += ft_printf_p(va_arg(args, void *));
	else if (str_i == 'd' || str_i == 'i')
		sum += ft_printf_d(va_arg(args, int));
	else if (str_i == 'u')
		sum += ft_printf_u(va_arg(args, unsigned int));
	else if (str_i == 'x' || str_i == 'X')
		sum += ft_printf_x(va_arg(args, int), str_i);
	else if (str_i == '%')
		sum += ft_printf_c('%');
	else
		return (-1);
	return (sum);
}
