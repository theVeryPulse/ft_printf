/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:12:12 by juli              #+#    #+#             */
/*   Updated: 2023/11/16 21:57:38 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints a string to terminal, returns string length */

#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

int	ft_printf_s(char *s)
{
	int	len;

	len = (int)ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}
