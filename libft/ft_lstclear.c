/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:17:04 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/27 11:01:15 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Deletes and frees the given element and every successor of that element,
 *   using the function ’del’ and free(3).
 *   Finally, the pointer to the list must be set to NULL.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp != 0)
	{
		next = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = 0;
}
