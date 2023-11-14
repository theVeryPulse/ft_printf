/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Philip Li <LJHR.UK@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:19:43 by Philip Li         #+#    #+#             */
/*   Updated: 2023/11/14 17:06:31 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prints a character to terminal, return 1 as length of char */

#include <unistd.h>

int	ft_printf_c(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}
