/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:34:50 by juli              #+#    #+#             */
/*   Updated: 2023/11/15 19:44:50 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Reverse a give string */

#include <stddef.h>
#include "libft/libft.h"

void	str_rev(char *s)
{
	size_t	left;
	size_t	right;
	char	swap;

	left = 0;
	right = ft_strlen(s) - 1;
	while (left < right)
	{
		swap = s[left];
		s[left] = s[right];
		s[right] = swap;
		left++;
		right--;
	}
}
