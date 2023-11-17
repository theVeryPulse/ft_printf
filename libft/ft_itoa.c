/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:40:23 by juli              #+#    #+#             */
/*   Updated: 2023/11/17 16:01:42 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* tested: 03/11/2023 */

#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

#define INT_MAX_LEN (40)
#define DEC_BASE (10)

int	ft_abs(int n);

char	*ft_itoa(int n)
{
	int			i;
	bool		is_negative;
	char		s[INT_MAX_LEN];
	char const	*dec_chars = "0123456789";

	i = INT_MAX_LEN - 1;
	s[i--] = '\0';
	is_negative = n < 0;
	while (n >= DEC_BASE || n <= -(DEC_BASE))
	{
		s[i] = dec_chars[ft_abs(n % DEC_BASE)];
		n /= DEC_BASE;
		i--;
	}
	s[i] = dec_chars[ft_abs(n)];
	if (is_negative)
		s[--i] = '-';
	return (ft_strdup(&s[i]));
}

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int num = 50000;
	printf("%d (int)\n%s (char[])\n", num, ft_itoa(num));
	num = INT_MIN;
	printf("%d (int)\n%s (char[])\n", num, ft_itoa(num));
	num = INT_MAX;
	printf("%d (int)\n%s (char[])\n", num, ft_itoa(num));
	return (0);
}
*/
