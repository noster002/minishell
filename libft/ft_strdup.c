/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:39:08 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 10:41:28 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + duplicates string s into memory obtained with malloc(3);
 *   can be freed with free(3)
 * + returns a pointer to the duplicated string
 *   It returns NULL if insufficient memory was available.
 * + man strdup
 */

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	count;
	int		i;

	count = ft_strlen(s);
	i = 0;
	d = (char *)malloc(count + 1);
	if (d != 0)
	{
		while (count > 0)
		{
			d[i] = s[i];
			i++;
			count--;
		}
	}
	d[i] = 0;
	return (d);
}
