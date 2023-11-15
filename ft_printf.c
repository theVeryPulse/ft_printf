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
#include <stdlib.h>
#include <unistd.h>
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
		{
			sum += ft_printf_c(str[i]);
			i++;
		}
		else // cspdiuxX%
		{
			/* ft_printf_c */
			if (str[i + 1] == 'c')
			{
				sum += ft_printf_c(va_arg(args, int));
				i += 2;
			}
			/* ft_printf_s */
			else if (str[i + 1] == 's')
			{
				sum += ft_printf_s(va_arg(args, char *));
				i += 2;
			}
			/* ft_printf_p */
			else if (str[i + 1] == 'p')
			{
				sum += ft_printf_p(va_arg(args, void *));
				i += 2;
			}
			/* ft_printf_d */
			else if (str[i + 1] == 'd')
			{
				sum += ft_printf_d(va_arg(args, int));
				i += 2;
			}
			/*
			else if (str[i + 1] == 'i')
			{
				;
			}
			else if (str[i + 1] == 'u')
			{
				;
			}
			else if (str[i + 1] == 'x')
			{
				;
			}
			else if (str[i + 1] == 'X')
			{
				;
			}
			*/
			else if (str[i + 1] == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				sum++;
				i++;
			}
		}
	}
	va_end(args);
	return (sum);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	int c_len = printf("abcd%c %s", 'A', "string");
	int ft_len = ft_printf("abcd%c %s", 'A', "string");
	write(STDOUT_FILENO, "\n", 1);
	printf("\tTotal length should be (%d), is now (%d)\n", c_len, ft_len);
}*/
