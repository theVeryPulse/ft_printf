/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:33:34 by juli              #+#    #+#             */
/*   Updated: 2023/11/05 18:29:23 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* last tested on 05/11/2023 */

/*	LOG

	05/11/2023
	Bug fix: handle overflow -> int c as char

	04/11/2023
	Bug fix: return terminator if looking for '\0'
*/

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <string.h>

int	main(void)
{
	char str[] = "tripouille";
	char c = 't' + 256;
	printf("ft: (%c) in (%s): (%s) at (%p)\n",
		c, str, ft_strchr(str, 't' + 256), ft_strchr(str, 't' + 256));
	printf("c:  (%c) in (%s): (%s) at (%p)\n",
		c, str, strchr(str, 't' + 256), strchr(str, 't' + 256));
}
*/
