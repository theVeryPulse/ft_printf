/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:56 by juli              #+#    #+#             */
/*   Updated: 2023/11/17 17:06:05 by juli             ###   ########.fr       */
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

#include "libftprintf.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

static bool	is_specifier(char c);

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
		if (str[i] != '%')
			sum += ft_printf_c(str[i]);
		else if (is_specifier(str[i + 1]))
			sum += ft_printf_all(args, str[++i]);
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (sum);
}

/* Check if input character is a valid specifier (cspiduxX%) */
static bool	is_specifier(char c)
{
	static const char	*specifiers = "cspdiuxX%%";

	return (ft_strchr(specifiers, c) != NULL);
}
