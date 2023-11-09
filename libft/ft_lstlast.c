/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:26:26 by juli              #+#    #+#             */
/*   Updated: 2023/11/08 17:33:50 by juli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Description
	Returns the last node of the list. */

/*	08/11/2023
	Bug fix: return NULL when input is NULL

*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
