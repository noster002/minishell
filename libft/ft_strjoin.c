/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:16:59 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 13:40:57 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a new string,
 *   which is the result of the concatenation of ’s1’(prefix) and ’s2’(suffix).
 * + returns the new string or NULL if the allocation fails
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = (char *)malloc(len_s1 + len_s2 + 1);
	len_s1 = 0;
	len_s2 = 0;
	if (new_str != 0)
	{
		while (s1[len_s1] != 0)
		{
			new_str[len_s1] = s1[len_s1];
			len_s1++;
		}
		while (s2[len_s2] != 0)
		{
			new_str[len_s1 + len_s2] = s2[len_s2];
			len_s2++;
		}
		new_str[len_s1 + len_s2] = 0;
	}
	return (new_str);
}
