/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:25:41 by nosterme          #+#    #+#             */
/*   Updated: 2021/06/03 15:18:56 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Iterates the list ’lst’ and applies the function ’f’
 *   to the content of each element.
 *   Creates a new list resulting of the successive applications
 *   of the function ’f’.
 *   The ’del’ function is used to delete the content of an element if needed.
 * + returns the new list or NULL if the allocation fails
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	first = 0;
	while (lst != 0)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == 0)
		{
			ft_lstclear(&first, (*del));
			return (0);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
