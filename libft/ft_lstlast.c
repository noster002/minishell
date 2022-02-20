/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:52 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/26 11:39:38 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + returns the last element of the list
 */

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
