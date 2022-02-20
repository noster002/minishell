/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:53:37 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 15:42:00 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + locates the first occurrence of the null-terminated string little
 *   in the string big, where not more than len characters are searched
 * + If little is an empty string, big is returned.
 *   If little occurs nowhere in big, NULL is returned.
 *   Otherwise a pointer to the first character
 *   of the first occurrence of little is returned.
 * + man strnstr (bsd-library)
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	j = 0;
	while (j < len && big[j])
	{
		i = 0;
		while (j < len && big[j] == little[i] && little[i] && big[j])
		{
			i++;
			j++;
		}
		if (little[i] == 0)
			return ((char *)big + (j - i));
		j = j - i + 1;
	}
	return (0);
}
