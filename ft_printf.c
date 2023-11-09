/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:19:09 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/09 18:55:50 by Philip Li        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		sum;
	char	*strout;
	va_list	args;

	va_start(args, str);
	strout = va_arg(args, char *);
	ft_putstr_fd((char *)str, STDOUT_FILENO);
	ft_putstr_fd(strout, STDOUT_FILENO);
	va_end(args);
	sum = 1;
	return (sum);
}