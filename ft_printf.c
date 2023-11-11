/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:09 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/11 19:34:10 by Philip Li        ###   ########.fr       */
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
	└─ ft_printf_c.c
	└─ ft_printf_s.c
	└─ ft_printf_p.c
	└─ ft_printf_d.c
	└─ ft_printf_i.c
	└─ ft_printf_u.c
	└─ ft_printf_x.c
	└─ ft_printf_X.c
	└─ ft_printf_percentsign.c
*/

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h> /* va_arg */
#include <stdint.h> /* ft_print_s */
/*
void	ptr_hexa(void *p)
{
	;
}

int	ft_print_p(void *addr)
{
	intptr_t	addr_int;
	int			i;
	char		hexstr[16];
	char const	*hexchars = "0123456789abcdef";

	addr_int = (intptr_t)addr;
	i = 0;
	while (i <= 15)
	{
		hexstr[15 - i] = hexchars[addr_int >> (i * 4) & 0xf];
		i++;
	}
	i = 0;
	write(1, hexstr, 16);
}*/

int	ft_printf(const char *str, ...)
{
	//char	*strout;
	size_t	i;
	size_t	sum;
	va_list	args;

	char c;
	char *s;
	//void *p;
	//unsigned long long d;

	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			sum++;
			i++;
		}
		else // cspdiuxX%
		{
			if (str[i + 1] == 'c')
			{
				c = va_arg(args, int);
				ft_putchar_fd(c, STDOUT_FILENO);
				sum++;
				i += 2;
				/* 3 variables: i, sum, va_arg(args, int) */
			}
			else if (str[i + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, STDOUT_FILENO);
				sum += ft_strlen(s);
				i += 2;
				/* 3 variables: i, sum, va_arg(args, char *) */
			}


			/*
			else if (str[i + 1] == 'p')
			{
				p = va_arg(args, void *);
				s = ptr_hexa(p);
				ft_putstr_fd(s, STDOUT_FILENO);
				sum += ft_strlen(s);
				i += 2;
			}
			else if (str[i + 1] == 'd')
			{
				d = va_arg(args, long long);
			}
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
			else if (str[i + 1] == '%')
			{
				;
			}
			*/
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
