/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:06:24 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/27 11:18:42 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Iterates the list ’lst’ and applies the function ’f’
 *   to the content of each element.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
