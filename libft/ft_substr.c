/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:31:50 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/14 15:13:00 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a substring from the string ’s’.
 *   The substring begins at index ’start’ and is of maximum size ’len’.
 * + returns the substring or NULL if the allocation fails
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	count = 0;
	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = (char *)malloc((len + 1) * sizeof(*s));
	if (substr != 0)
	{
		while (count < len)
		{
			substr[count] = s[start + count];
			count++;
		}
		substr[count] = 0;
	}
	return (substr);
}
