/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:15:25 by juli              #+#    #+#             */
/*   Updated: 2023/11/15 19:43:56 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints a integer to terminal, return string length */

#include <unistd.h>
#include <stddef.h>
#include "libftprintf.h"
#include "libft/libft.h"
#define DEC_BASE (10)

int	ft_printf_d(int num)
{
	int			i;
	char		decstr[50];
	char const	*dec_chars = "0123456789";

	i = 0;
	while (num / DEC_BASE)
	{
		decstr[i++] = dec_chars[num % DEC_BASE];
		num /= DEC_BASE;
	}
	decstr[i++] = dec_chars[num];
	decstr[i] = '\0';
	str_rev(decstr);
	write(STDOUT_FILENO, decstr, ft_strlen(decstr));
	return (ft_strlen(decstr));
}
